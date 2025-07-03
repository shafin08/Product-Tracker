# Product Tracker

# Description
This product tracker is a useful tool for manufacturers who sells many different products and want to track important information regarding their product.


# Features
Allows you to create a database that track the sales, profit and profit margin of your product.                  
A live tracking mode that allows you to make direct changes to your database and see those changes in real time. 
Display a clear table of each product sales, profit, and profit margin.                                                                                                         
Display total profit and average profit margin.

# Input
Each product have the following attributes:
- Product ID (integer $>0$).
- Manufacturer sale price (integer $>0$).
- Retail price (integer $>0$).

Part 1: Initialize the database                                                                                                        
The first line is the amount of product you want to include in your database.                                    
The following lines will be asked to input the product ID, product sale price, retail price.                     

Example:
```
2(Amount of Product)
2(Prod ID) 4000(Sale Price) 5000(Retail Price)
1 200 250
```

Part 2 - Live tracking mode
Immediately after part 1's input, the program enters part 2 - live tracking mode. Each line of part 2's input will be a single integer code. Unlike part 1, part 2's input can have any number of lines.

There are 3 different types of codes:                                                                            

1. Product Sale:
Typing the product ID equals one sale. 

2. Display Sales information:
Typing -1 will display a table that shows all the necessary sale information along with total profit and average profit margin.

Typing -2 will display the final table, final profit and final average profit margin and end the program.

# Ouput
Item with no sales is omitted when product the sales table.

Example of the output table:
```

Sales:
+---------+---------+------------+--------+
| ID      | Sold    | Profit ($) | GM (%) |
+---------+---------+------------+--------+
| 1       | 1       | 50         |  20.00 |
+---------+---------+------------+--------+
| 5       | 20      | 120        |   5.00 |
+---------+---------+------------+--------+
    ...       ...       ...         ...
+---------+---------+------------+--------+
| 2       | 4       | 40         |   1.00 |
+---------+---------+------------+--------+
Total profit: $50
Average GM: 20.00%
```

## Example I/O


### Example 1
Input:
```
2
2 4000 5000
1 200 250
1
-1
2
-2
```

Output:
```

Sales:
+---------+---------+------------+--------+
| ID      | Sold    | Profit ($) | GM (%) |
+---------+---------+------------+--------+
| 1       | 1       | 50         |  20.00 |
+---------+---------+------------+--------+
Total profit: $50
Average GM: 20.00%

Sales:
+---------+---------+------------+--------+
| ID      | Sold    | Profit ($) | GM (%) |
+---------+---------+------------+--------+
| 2       | 1       | 1000       |  20.00 |
| 1       | 1       | 50         |  20.00 |
+---------+---------+------------+--------+
Total profit: $1050
Average GM: 20.00%

```

### Example 2
Input:
```
3
3 2299 3180
2 3920 4590
1 999 1379
1
-1
1
2
2
-2
```

Output:
```

Sales:
+---------+---------+------------+--------+
| ID      | Sold    | Profit ($) | GM (%) |
+---------+---------+------------+--------+
| 1       | 1       | 380        |  27.56 |
+---------+---------+------------+--------+
Total profit: $380
Average GM: 27.56%

Sales:
+---------+---------+------------+--------+
| ID      | Sold    | Profit ($) | GM (%) |
+---------+---------+------------+--------+
| 1       | 2       | 760        |  27.56 |
| 2       | 2       | 1340       |  14.60 |
+---------+---------+------------+--------+
Total profit: $2100
Average GM: 21.08%
```

### Example 3
Input:
```
4
1 4956 5423
4 2506 2831
3 4007 4072
2 3571 4939
4
1
5
-1
4
2
3
2
4
-2
```

Output:
```
Invalid code 5 is not a valid product ID. Ignoring.

Sales:
+---------+---------+------------+--------+
| ID      | Sold    | Profit ($) | GM (%) |
+---------+---------+------------+--------+
| 4       | 1       | 325        |  11.48 |
| 1       | 1       | 467        |   8.61 |
+---------+---------+------------+--------+
Total profit: $792
Average GM: 10.05%

Sales:
+---------+---------+------------+--------+
| ID      | Sold    | Profit ($) | GM (%) |
+---------+---------+------------+--------+
| 2       | 2       | 2736       |  27.70 |
| 4       | 3       | 975        |  11.48 |
| 1       | 1       | 467        |   8.61 |
| 3       | 1       | 65         |   1.60 |
+---------+---------+------------+--------+
Total profit: $4243
Average GM: 14.29%
```
