#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int id[n];
    int msp[n];
    int rp[n];
    int amt_sales[n];
    int total_sales[n];
    int profit[n];
    float profit_marg[n];
    for (int k = 0; k<n; k++){
        profit[k] = 0;
        total_sales[k] = 0;
        amt_sales[k] = 0;
        profit_marg[k] = 0.0f;

    }
    for(int i = 1; i<=n; i++){
        scanf("%d %d %d", &id[i-1], &msp[i-1], &rp[i-1]);
    }
    for (int i = 0; i<n; i++){
        if(id[i]<0 || msp[i]<0 || rp[i]<0){
            return 1;
        }
    }
    while(1){
        int input = 0;
        scanf("%d", &input);
        if (input > 0){
            bool found = false;
            found = false;
            for (int j = 0; j<n; j++){
                if (input == id[j]){
                    amt_sales[j] += 1;
                    total_sales[j] += rp[j];
                    profit[j] += (rp[j] - msp[j]);
                    found = true;
                    break;
                }
            }
            if (!found){
             printf("Invalid code %d is not a valid product ID. Ignoring.\n", input);
            }
        }
        if (input == -2 || input == -1){
            int index[n];
            for (int w = 0; w<n; w++){
                index[w] = w;
            }
            int total_profit = 0;
            float sum_m = 0.0f;
            int sum_q = 0;
            for (int i = 0; i<n; i++){
                if (amt_sales[i] > 0){
                    profit_marg[i] = ((float)profit[i]/(float)total_sales[i])*100;
                    total_profit += profit[i];
                }
                else{
                    profit_marg[i] = 0.0f;
                }

            }
            for (int i = 0; i < n-1; i++){
                float temp;
                int temp_a;
                for (int j = 0; j< n-i-1; j++){
                    if (profit_marg[j] < profit_marg[j+1]){
                        temp = profit_marg[j];
                        profit_marg[j] = profit_marg[j+1];
                        profit_marg[j+1] = temp;
                        temp_a = index[j];
                        index[j] = index[j+1];
                        index[j+1] = temp_a;
                    }
                }
            }
            for (int i = 0; i<n; i++){
                sum_m += amt_sales[index[i]] * profit_marg[i];
                sum_q += amt_sales[index[i]];
            }
            printf("\n");
            printf("Sales:\n");
            printf("+---------+---------+------------+--------+\n");
            printf("| %-7s | %-7s | %-10s | %6s |\n", "ID","Sold","Profit ($)","GM (%)");
            printf("+---------+---------+------------+--------+\n");
            for (int i = 0; i<n; i++){
                if (amt_sales[index[i]]>0){
                    printf("| %-7d | %-7d | %-10d | %6.2f |\n", id[index[i]], amt_sales[index[i]], profit[index[i]], profit_marg[i]);
                }
            }
            printf("+---------+---------+------------+--------+\n");
            printf("Total profit: $%d\n", total_profit);
            printf("Average GM: %.2f%%\n", sum_m/sum_q);
            if (input == -2){
                break;
            }
        }
    }

    return 0;
}
