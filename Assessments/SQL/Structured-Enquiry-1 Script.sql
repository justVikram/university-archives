CREATE DATABASE STRUCTURED_ENQUIRY;

CREATE TABLE company
(
    company_id       int
        PRIMARY KEY,
    company_name     varchar(20)
        NOT NULL,
    date_established date
        NOT NULL
);

CREATE TABLE staff
(
    staff_id   int
        PRIMARY KEY,
    first_name varchar(10)
        NOT NULL,
    last_name  varchar(10)
        NOT NULL,
    gender     varchar(1)
        NOT NULL,
    age        int,
    salary     int
        NOT NULL,
    phone_no   int
        NOT NULL,
    company_id int,

    FOREIGN KEY (company_id) REFERENCES company (company_id)
);

CREATE TABLE product
(
    product_id   int
        PRIMARY KEY,
    product_name varchar(15)
        NOT NULL,
    category     varchar(15)
        NOT NULL,
    price        int
        NOT NULL,
    expiry_date  date
        NOT NULL
);

CREATE TABLE customer
(
    ph_no       int
        PRIMARY KEY,
    name        varchar(15)
        NOT NULL,
    addr_line_1 varchar(20)
        NOT NULL,
    addr_line_2 varchar(20)
        NOT NULL,
    addr_line_3 varchar(20)
        NOT NULL
);

CREATE TABLE transaction
(
    txn_id        int
        PRIMARY KEY,
    order_time    date
        NOT NULL,
    total_amount  int
        NOT NULL,
    delivery_time date,
    cust_ph_no    int
        REFERENCES customer (ph_no),
    staff_id      int,

    FOREIGN KEY (cust_ph_no) REFERENCES customer (ph_no),
    FOREIGN KEY (Staff_id) REFERENCES staff (staff_id)
);

CREATE TABLE products_sold
(
    txn_id     int,
    product_id int,

    FOREIGN KEY (txn_id) REFERENCES transaction (txn_id)
        ON UPDATE CASCADE ON DELETE CASCADE,
    FOREIGN KEY (product_id) REFERENCES product (product_id)
        ON UPDATE CASCADE ON DELETE CASCADE
);

INSERT INTO company
VALUES (1, 'Swiggy', '2016-07-11');

INSERT INTO company
VALUES (2, 'Zomato', '2015-04-16');

INSERT INTO company
VALUES (3, 'Food Panda', '2014-09-21');

INSERT INTO company
VALUES (4, 'Uber Eats', '2015-01-25');

INSERT INTO company
VALUES (5, 'Dominos', '2011-11-06');

INSERT INTO staff
VALUES (1, 'Ram', 'Kumar', 'M', 45, 20000, 99923456, 3);

INSERT INTO staff
VALUES (2, 'Ashish', 'Chattoraj', 'M', 37, 25000, 98537861, 4);

INSERT INTO staff
VALUES (3, 'Ajay', 'Khare', 'M', 40, 23000, 99348501, 2);

INSERT INTO staff
VALUES (4, 'Soham', 'Pandey', 'M', 29, 27000, 98876912, 2);

INSERT INTO staff
VALUES (5, 'Adya', 'Mishra', 'F', 26, 22000, 98348791, 1);

INSERT INTO product
VALUES (1, 'Maggi Noodles', 'Noodles', 100, '2022-10-12');

INSERT INTO product
VALUES (2, 'Sunfeast Cookie', 'Biscuits', 50, '2022-10-13');

INSERT INTO product
VALUES (3, 'Cadbury Choco', 'Chocolates', 75, '2022-10-14');

INSERT INTO product
VALUES (4, 'Maggi Pazzta', 'Noodles', 90, '2022-10-15');

INSERT INTO product
VALUES (5, 'Cadbury Bourbon', 'Biscuits', 120, '2022-10-16');

INSERT INTO customer
VALUES (98563412, 'Amit', '1/4', 'Amaltas Parisar', 'DP Road');

INSERT INTO customer
VALUES (96768982, 'Prakash', '220', 'Neelkanth Greens', 'Kalali');

INSERT INTO customer
VALUES (93348126, 'Rohan', '1004', 'Supertech Boulevard', 'Sector 93 - A');

INSERT INTO customer
VALUES (93348981, 'Nachiket', '2/5', 'Royal City', 'Sector 150');

INSERT INTO customer
VALUES (96568726, 'Harman', '101', 'Siddhachal Phase 3', 'Godbunder Road');

INSERT INTO transaction
VALUES (1, '2021-04-15', 300, '2021-04-16', 98563412, 3);

INSERT INTO transaction
VALUES (2, '2021-04-16', 400, '2021-04-17', 93348126, 4);

INSERT INTO transaction
VALUES (3, '2021-04-17', 150, '2021-04-18', 96568726, 1);

INSERT INTO transaction
VALUES (4, '2021-04-18', 270, '2021-04-19', 96768982, 4);

INSERT INTO transaction
VALUES (5, '2021-04-19', 75, '2021-04-20', 93348981, 5);

-- UPDATE --

# Ajay Khare now works for Company with Company ID = 5.

UPDATE staff
SET company_id = 5
WHERE first_name = 'Ajay'
  AND last_name = 'Khare';

# Nachiket relocated to 455, Sun & Sands, Al Rigga.

UPDATE customer
SET addr_line_1 = '455',
    addr_line_2 = 'Sun & Sands',
    addr_line_3 = 'Al Rigga'
WHERE name = 'Nachiket';

-- OPERATORS --

# Display all products whose prices are greater than Rs. 100.

SELECT *
FROM product
WHERE price > 100;

# List all companies established after 2016.

SELECT *
FROM company
WHERE date_established > '2016-01-01';

-- ORDER  BY --

# Show all transactions made in a chronological order.

SELECT *
FROM transaction
ORDER BY order_time;

# Show all products, filter by price (high to low).

SELECT *
FROM product
ORDER BY price;

-- AGGREGATE FUNCTIONS --

# Find out total number of orders placed by each customer.

SELECT COUNT(*),
       c.name
FROM customer c,
     transaction t
WHERE c.ph_no = t.cust_ph_no
GROUP BY cust_ph_no;

# Find out the names of the staffs receiving the least salary.

SELECT s.first_name,
       s.last_name,
       s.salary
FROM staff s
WHERE s.salary =
      (
          SELECT MIN(salary) AS min_salary
          FROM staff
      );

-- HAVING CLAUSE --

# Display names of those customers than have  spent at least 250 on deliveries.

SELECT c.name,
       SUM(t.total_amount) AS total_amt_paid
FROM transaction t,
     customer c
WHERE c.ph_no = t.cust_ph_no
GROUP BY c.ph_no
HAVING SUM(t.total_amount) > 250
ORDER BY SUM(t.total_amount);

# Display names of all those staffs who have processed more than one transactions.

SELECT s.first_name,
       s.last_name,
       COUNT(*) AS no_of_txns_processed
FROM transaction t,
     staff s
WHERE s.staff_id = t.staff_id
GROUP BY s.staff_id
HAVING COUNT(*) > 1;

-- SUB-QUERIES --

# List all the customers who have purchased Maggi Pazzta.

SELECT c.name
FROM transaction t,
     products_sold ps,
     customer c,
     product p
WHERE p.product_id =
      (
          SELECT pp.product_id
          FROM product pp
          WHERE pp.product_name = 'Maggi Pazzta'
      )
  AND p.product_id = ps.product_id
  AND ps.txn_id = t.txn_id
  AND t.cust_ph_no = c.ph_no;

# List the number of staffs who have processed a transaction for Prakash.

SELECT COUNT(*) AS no_of_staffs
FROM customer c1,
     transaction t,
     staff s
WHERE c1.ph_no =
      (
          SELECT c2.ph_no
          FROM customer c2
          WHERE c2.name LIKE 'Pr%sh'
      )
  AND c1.ph_no = t.cust_ph_no
  AND t.staff_id = s.staff_id
GROUP BY t.cust_ph_no;

-- Quantified Sub-queries --

# Display details of most expensive product.

SELECT *
FROM product p
WHERE p.price >= ALL
      (
          SELECT p2.price
          FROM product p2
      );

# Display the company name with the most number of staffs.

SELECT COUNT(*) AS no_of_staffs,
       c.company_name
FROM company c,
     staff s
WHERE s.company_id = c.company_id
GROUP BY s.company_id
HAVING COUNT(*) >= ALL
       (
           SELECT COUNT(*)
           FROM staff s_inner
           GROUP BY s_inner.company_id
       );

-- Correlated Sub-queries --

# List those staffs that have the same salary as Adya.

SELECT *
FROM staff s_outer
WHERE EXISTS
          (
              SELECT *
              FROM staff s_inner
              WHERE s_inner.salary = s_outer.salary
                AND s_inner.first_name LIKE 'A%a'
          );

# List details of the most expensive transaction made.

SELECT *
FROM transaction t_outer
WHERE NOT EXISTS
    (
        SELECT *
        FROM transaction t_inner
        WHERE t_inner.total_amount > t_outer.total_amount
    );

-- VIEWS --

#  Create a view linking each staff to the transactions they have processed.

CREATE VIEW TransactionsMadeByStaff AS
SELECT s.first_name,
       s.last_name,
       t.txn_id
FROM staff s,
     transaction t
WHERE s.staff_id = t.staff_id;

SELECT *
FROM TransactionsMadeByStaff;

# Create a view linking each customer to their most expensive order

CREATE VIEW MostExpensiveOrders AS
SELECT c.name,
       MAX(t.total_amount) AS most_exp_order_amt
FROM customer c,
     transaction t
WHERE c.ph_no = t.cust_ph_no
GROUP BY t.cust_ph_no;

SELECT *
FROM MostExpensiveOrders;

-- JOINS --

# List customer's details for each transaction they have made.

SELECT *
FROM customer
         LEFT JOIN transaction t
                   ON customer.ph_no = t.cust_ph_no;

#  For each company, list their details along with the staffs' details who work for it.

SELECT *
FROM staff
         RIGHT JOIN company c
                    on c.company_id = staff.company_id;