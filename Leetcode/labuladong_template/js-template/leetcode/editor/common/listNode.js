export class ListNode {
    constructor(val, next) {
        this.val = (val === undefined ? 0 : val);
        this.next = (next === undefined ? null : next);
    }

    static print(head) {
        let current = head;
        let s = ""
        while (current !== null) {
            s += current.val + (current.next ? "->" : "");
            current = current.next;
        }
        console.log(s);
    }

    static createHead(nums) {
        let head = new ListNode();
        let current = head;
        for (let i = 0; i < nums.length; i++) {
            current.next = new ListNode(nums[i]);
            current = current.next;
        }
        return head.next;
    }
}
