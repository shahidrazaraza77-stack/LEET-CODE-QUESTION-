class Solution {
public:
    int subtractProductAndSum(int n) {
        int product =1;
        int sum=0;
        while (n!=0){
            int digit =n%10;
            product=digit*product;
            sum=digit+sum;
            n=n/10;

        }return product-sum;
        
        
    }
};