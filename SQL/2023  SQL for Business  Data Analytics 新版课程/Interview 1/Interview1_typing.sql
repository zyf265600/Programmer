SELECT SUBSTRING(pmt_date, 1, 7) as Month, 
Case When pmt_type IN (1,2,5,12,13) Then 'AutoPay'
	 When pmt_type IN (18,20,28,25) Then 'Branch'
     When pmt_type IN (30,49,50) Then 'EOS'
     When pmt_type IN (200,222,205) Then 'IVR'
     When pmt_type IN (300,301,401) Then 'Paper'
     When pmt_type IN (726,756,765) Then 'Third Party'
     When pmt_type IN (980,990,991,999) Then 'Mobile phone pay'
     else 'Others'
     End as 'Payment_Type', 
Count(*) as Payment_cnt 
FROM pmt_dt_detail
WHERE SUBSTRING(pmt_date,1,7) = '2014-07' AND country_code =1
Group By 1, 2;