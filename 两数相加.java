package practice;

import java.util.Scanner;

/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
 */
public class 两数相加 {
    private static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
        }
    }

    private static ListNode createLinkedList(int[] nums){
        ListNode head = null;
        ListNode tail = null;
        for (int i = 0; i < nums.length; i++) {
            ListNode list = new ListNode(nums[i]);
            list.next = null;
            if (tail == null){
                head = tail = list;
            }else{
                tail.next = list;
                tail = list;
            }
        }
        return head;
    }

     public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
         /*ListNode list1 = l1;
         ListNode list2 = l2;
         ListNode tail = null;
         ListNode head = null;
         int add = 0;
         while(list1!=null&&list2!=null){
             int key = list1.val+list2.val+add;
             if (key>=10){
                 key = key%10;
                 add = 1;
             }else{
                 add = 0;
             }
             ListNode list = new ListNode(key);
             list.next = null;
             if (head==null){
                 head=tail=list;
             }else{
                 tail=tail.next=list;
             }
             list1 = list1.next;
             list2 = list2.next;
         }
         while(list1!=null){//list1没完
             int key = add + list1.val;
             if (key>=10){
                 key = key%10;
                 add = 1;
             }else{
                 add = 0;
             }
             ListNode list = new ListNode(key);
             list.next = null;
             tail = tail.next = list;
             list1 = list1.next;
         }
         while(list2!=null){//list2没完
             int key = add + list2.val;
             if (key>=10){
                 key = key%10;
                 add = 1;
             }else{
                 add = 0;
             }
             ListNode list = new ListNode(key);
             list.next = null;
             tail = tail.next = list;
             list2 = list2.next;
         }
         if (list1==list2&&list1==null&&add==1){
             ListNode list = new ListNode(1);
             list.next = null;
             tail = tail.next = list;
         }
         return head;*/

         /*ListNode dummyHead = new ListNode(0);
         ListNode p = l1, q = l2, curr = dummyHead;
         int carry = 0;
         while (p != null || q != null) {
             int x = (p != null) ? p.val : 0;
             int y = (q != null) ? q.val : 0;
             int sum = carry + x + y;
             carry = sum / 10;
             curr.next = new ListNode(sum % 10);
             curr = curr.next;
             if (p != null) p = p.next;
             if (q != null) q = q.next;
         }
         if (carry > 0) {
             curr.next = new ListNode(carry);
         }
         return dummyHead.next;*/

         ListNode result = new ListNode(0);
         int flag=0;
         ListNode listNode=result;
         int x;
         while (l1 != null || l2 != null)
         {
             x=flag;
             if(l1!=null)
             {
                 x+=l1.val;
                 l1=l1.next;
             }
             if(l2!=null)
             {
                 x+=l2.val;
                 l2=l2.next;
             }
             if(x>9)
             {
                 flag=1;
                 x=x-10;
             }else flag=0;
             result.next = new ListNode(x);
             result=result.next;
         }
         if(flag!=0)
             result.next=new ListNode(1);
         return listNode.next;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("请输入数组1和数组2的长度:");
        int n1 = in.nextInt();
        int n2 = in.nextInt();
        System.out.print("输入数组1的值：");
        int[] nums1 = new int[n1];
        for (int i = 0; i < n1; i++) {
            nums1[i] = in.nextInt();
        }
        System.out.print("输入数组2的值：");
        int[] nums2 = new int[n2];
        for (int i = 0; i < n2; i++) {
            nums2[i] = in.nextInt();
        }
        ListNode l1 = createLinkedList(nums1);
        ListNode l2 = createLinkedList(nums2);
        ListNode l3 = addTwoNumbers(l1,l2);
        for (; l3!=null ; l3=l3.next) {
            System.out.println(l3.val);
        }
    }

}
