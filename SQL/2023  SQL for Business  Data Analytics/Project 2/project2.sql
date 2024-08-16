/* 
	Project 2 Credit Limit Increase Campaign
*/

# 2 -- 2023.5.2
SELECT * FROM campaign.base;
SELECT * FROM campaign.call_record;
SELECT * FROM campaign.decision;
SELECT * FROM campaign.change_record;
SELECT * FROM campaign.letter;

-- 1
SELECT call_date, count(*) AS num_response
FROM campaign.call_record
Group By call_date
Order By 1;

-- 2
SELECT 
sum(case when decision_status = 'AP' then 1 else 0 end) / count(acct_decision_id) as approval_rate,
sum(case when decision_status = 'DL' then 1 else 0 end) / count(acct_decision_id) as decline_rate
FROM campaign.decision;

-- 3
SELECT acct_num, credit_limit, offer_diff AS offer_amount, credit_limit_after, Approved, credit_limit + offer_diff - credit_limit_after AS Mismatch
FROM (
	SELECT *, CASE WHEN B.offer_diff <> CR.result_diff  THEN 'Mismatched'
			  WHEN B.credit_limit <> CR.credit_limit_before THEN 'Current Info Error'
			  ELSE 'Matched'
			  END AS Approved
	FROM (
		SELECT acct_num, credit_limit, offer_amount AS offer_diff FROM campaign.base
		) AS B 
		JOIN 
		(
		SELECT account_number, credit_limit_before, (credit_limit_after - credit_limit_before) AS result_diff, credit_limit_after FROM campaign.change_record
		) AS CR
		ON B.acct_num = CR.account_number) AS result                                         
WHERE Approved = 'Mismatched';

-- 4.1
SELECT acct_decision_id, Letter_trigger_date, decision_date
FROM campaign.decision AS d LEFT JOIN campaign.letter AS l ON d.acct_decision_id = l.account_number
WHERE Letter_trigger_date < decision_date or letter_trigger_date is NULL;
     
-- 4.2
SELECT * 
FROM (
	SELECT *, Case When (decision_status = 'AP' AND letter_code = 'AE001' AND language = 'English') THEN 'Match'
			   When (decision_status = 'AP' AND letter_code = 'AE002' AND language = 'French') THEN 'Match'
               When (decision_status = 'DL' AND letter_code = 'RE001' AND language = 'English') THEN 'Match'
               When (decision_status = 'DL' AND letter_code = 'RE002' AND language = 'French') THEN 'Match'
               ELSE 'Unmatched' END AS letter_code_status
	FROM campaign.decision AS d LEFT JOIN campaign.letter AS l ON d.acct_decision_id = l.account_number) AS result
WHERE letter_code_status = 'Unmatched';

-- 5
SELECT b.acct_num, b.credit_limit, b.offer_amount, d.decision_status, d.decision_date, l.Letter_trigger_date, l.letter_code, l.language, cr.credit_limit_after,

CASE WHEN mismatch.Approved = 'Mismatched' OR mismatch.Approved = 'Current Info Error' THEN 1
	 WHEN mismatch.Approved = 'Matched' OR mismatch.Approved IS NULL THEN 0 
     ELSE 'Invalid' END AS mismatch_flag,
     
CASE WHEN missing.Letter_trigger_date < missing.decision_date or missing.Letter_trigger_date is NULL THEN 1
	 ELSE 0 END AS mismatch_flag,
     
CASE WHEN wrong.letter_code_status = 'Unmatched' THEN 1
     WHEN wrong.letter_code_status = 'Match' THEN 0
     ELSE 'Invalid' END AS wrong_letter_flag

FROM campaign.base AS b JOIN campaign.decision AS d ON b.acct_num = d.acct_decision_id
JOIN campaign.letter AS l ON b.acct_num = l.account_number
LEFT JOIN campaign.change_record AS cr ON l.account_number = cr.account_number

LEFT JOIN
(SELECT acct_num, credit_limit, offer_diff AS offer_amount, credit_limit_after, Approved, credit_limit + offer_diff - credit_limit_after AS Mismatch
FROM (
	SELECT *, CASE WHEN B.offer_diff <> CR.result_diff  THEN 'Mismatched'
			  WHEN B.credit_limit <> CR.credit_limit_before THEN 'Current Info Error'
			  ELSE 'Matched'
			  END AS Approved
	FROM (
		SELECT acct_num, credit_limit, offer_amount AS offer_diff FROM campaign.base
		) AS B 
		JOIN 
		(
		SELECT account_number, credit_limit_before, (credit_limit_after - credit_limit_before) AS result_diff, credit_limit_after FROM campaign.change_record
		) AS CR
		ON B.acct_num = CR.account_number) AS result)
AS mismatch ON b.acct_num = mismatch.acct_num

LEFT JOIN
(SELECT acct_decision_id, decision_date, letter_trigger_date
FROM campaign.decision AS d LEFT JOIN campaign.letter AS l ON d.acct_decision_id = l.account_number) 
AS missing ON b.acct_num = missing.acct_decision_id

LEFT JOIN
(SELECT * 
FROM (SELECT *, Case When (decision_status = 'AP' AND letter_code = 'AE001' AND language = 'English') THEN 'Match'
			   When (decision_status = 'AP' AND letter_code = 'AE002' AND language = 'French') THEN 'Match'
               When (decision_status = 'DL' AND letter_code = 'RE001' AND language = 'English') THEN 'Match'
               When (decision_status = 'DL' AND letter_code = 'RE002' AND language = 'French') THEN 'Match'
               ELSE 'Unmatched' END AS letter_code_status
	  FROM campaign.decision AS d LEFT JOIN campaign.letter AS l ON d.acct_decision_id = l.account_number) AS result)
AS wrong ON b.acct_num = wrong.acct_decision_id
;
