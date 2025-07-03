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

Part 2: Tracking Mode


Example:
```
2
2 4000 5000
1 200 250
```

### Part 2 - Live tracking mode
Immediately after part 1's input, the program enters part 2 - live tracking mode. Each line of part 2's input will be a single integer code. Unlike part 1, part 2's input can have any number of lines.

There are 3 different types of codes:
#### 1. Product Sale
- If `code` is a valid product ID, then the code type is **product sale**.
- This represents one single sale of the product with ID equal to `code`.
- The interface should keep track of the number of sales for the product with the ID that matches `code`. You can assume EPSILON has infinite stock of all vaild products entered.
#### 2. Display Sales Information
- If `code` is equal to either `-1`, or `-2`, then the code type is **display sales information**.
- The interface should immediately display the following:
    1. For each product sold today, show the product ID, quantity sold, profit (i.e., retail price $-$ manufacturer sale price), and profit margin (i.e., profit $/$ retail price).
        - **Should be sorted by profit margin descending**
        - See [the next section](#output-format) for formatting details
        - Exclude products with 0 sales
    2. Below the table, display the total profit, and the average profit margin for today.
- After displaying the sales information, if the code is `-1`, then the program should continue running. However, if the code is `-2`, then your program should end.


### Sales Table

The sales table to be printed out on `-1` or `-2` code should look like this:

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

**Details:**
- The row containing `...` represents other rows for the sake of this example and should not be part of the output.
- The `GM (%)` column is the profit margin column.
- Notice the empty line above `Sales:`, this should always be printed with the table. The purpose is to separate each table if more than one of them are printed consecutively.

**As stated above:**
1. The table **should be sorted by profit margin (`GM (%)`) descending**
2. Any items with `0` sales should be omitted.

Additionally, each column should be formatted in the following way

| Column | Alignment | Minimum Width |
| ------ | ---- | --- |
| `ID` | Left | $7$ |
| `Sold` | Left | $7$ |
| `Profit ($)` | Left | $10$ |
| `GM (%)` | Right | $6$, to two decimal places |

Each cell should also start and end with a space. So if the following cell displays `10`, is left-aligned, and has a minimum width of $3$ for example, it should look like the following

```
+-----+
| 10  |
+-----+
```

Notice how the number of characters between each `|` is $5$ and not $3$, this is because of the two extra spaces before and after the formatted integer.

Finally, the total profit and average profit margin values should be formatted without specifying a minimum width. Moreover, the average profit margin value should be printed to two decimal places.

### Invalid Code

The message to be printed on invalid code should be
```
Invalid code <code> is not a valid product ID. Ignoring.
```
Where `<code>` should be replaced with the given invalid code. No minimum width for the format should be specified.

## Efficiency
To handle the number of different products EPSILON has available and the quantities they are sold in, your program must be efficient. Your program will be tested on an input of $50,000$ different products and $10,000$ lines of input, which it must complete in under $20$ seconds (this is `./Testcases/14_input.txt`).

Achieving this speed can be accomplished with two conditions:
- Do not sort the list by profit margin each print. Sorting a large list is expensive and this quantity never changes, so do it once.
- Use binary search rather than linear search to search through item IDs each time an ID is entered into the system. While not as expensive as sorting, this is the most frequent operation you will do, and with a large enough number of items you will see a significant difference.

You now run into an issue:
1. printing in order of profit margin requires the list to be sorted by profit margin;
2. binary search on the ID requires the list to be sorted by ID;
3. You only want to sort once

Here's how you might avoid this issue. We can offer two options (mutually exclusive):
1. Sort the list by profit margin, allowing you to print in the correct order. Call this list A1 (it may actually be a set of parallel arrays, but this does not matter for the implementation). Then, create an index on the IDs of the products in A1. The index is a second list A2 consisting of the IDs sorted numerically, and the position of that product entry in the main list. You can perform a binary search on A2 and get the location of the corresponding entry in A1
2. Sort the list by ID, allowing you to binary search though it. Let's call this List B1. Create a second list B2, consisting of the indexes of B1 (originally 0, 1, 2...). Sort B2 list by the profit margin of the corresponding entry in B1. When printing, B2 defines the order in which the entries of B1 will be printed

## Example I/O
When printing the sales information, the table should be formatted as specified in the [output format section](#output-format).

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
