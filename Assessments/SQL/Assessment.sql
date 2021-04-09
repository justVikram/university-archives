drop table discount;
drop table preference;
drop table reservation;
drop table agent;
drop table room;
drop table room_type;
drop table credit_card;
drop table customer;


create table Customer
(
    CustId     int,
    First_name varchar(20),
    Last_name  varchar(20),
    Addrstreet
               varchar(50),
    Addrcity   varchar(50),
    Addrstate  varchar(20),
    Addrzip    varchar(20),
    phone      varchar(20),
    primary key (CustId)
);

create table Credit_Card
(
    Card_no  varchar(20),
    Cust_Id  int,
    CardType varchar(20)
        CHECK (CardType = 'Visa' or CardType = 'American Express' or CardType = 'MasterCard' or
               CardType = 'Maestro' or CardType = 'Delta' ),
    Exp_Date DATE,
    primary key (Card_no),
    foreign key (Cust_id) references Customer (CustId)
);

create table Room_Type
(
    Room_type   varchar(20),
    pricePerNgt int,
    BedType     varchar(20)
        CHECK (BedType = 'single' or BedType = 'double' or BedType = 'king size' or BedType = 'queen size'),
    SmokeOpt    varchar(20) CHECK (SmokeOpt = 'yes' or SmokeOpt = 'no'),
    primary key (Room_type)
);

create table Room
(
    RoomNo       int,
    RoomName     varchar(20),
    Desription   varchar(20),
    loction      varchar(20),
    RoomFloor    varchar(20) CHECK (RoomFloor >= 1 or RoomFloor <= 8),
    Availability varchar(20) CHECK (Availability = 'yes' or Availability = 'no'),
    primary key (RoomNo),
    foreign key (RoomName) references Room_Type (Room_type)
);

create table Agent
(
    AgentID   int,
    AgentName varchar(20),
    Company   varchar(20),
    Address   varchar(20),
    primary key (AgentID)
);

create table Reservation
(
    ConfirmNo        int,
    custId           int,
    RoomNo           int,
    amount           float,
    DiscountCode
                     varchar(20),
    Cancel_Date      date,
    cancel_option    varchar(20) CHECK (cancel_option = 'yes' or
                                        cancel_option = 'no'),
    Reservation_Date date,
    Departure_date   date,
    Arrival_date     date,
    AgentID          int,
    primary key (ConfirmNo),
    foreign key (custId) references Customer (CustId),
    foreign key (roomNo) references
        Room (RoomNo),
    foreign key (AgentID) references Agent (AgentID)
);

create table Preference
(
    Row_Id          int,
    PreferenceType  varchar(20),
    PreferenceValue int,
    PreferenceId    int,
    CustId          int,
    primary key (Row_Id),
    foreign key (CustId) references Customer (CustId)
);

create table Discount
(
    ConfirmNo      int,
    AgentID        int,
    DiscountAmount int,
    foreign key (AgentID)
        references Agent (AgentID),
    foreign key (ConfirmNo) references Reservation (confirmNo)
);


INSERT INTO customer
VALUES (14, 'Sukhraj', 'Singh', 'Boltsnagar', 'Nagpur',
        'Uttar Pradesh', '550010', '2345610');
INSERT INTO customer
VALUES (12, 'Vijayanand', 'Reddy', 'Gachibowli', 'Hyderabad',
        'Andhra Pradesh', '610010', '6523871');
INSERT INTO customer
VALUES (13, 'Anand', 'Mishra', 'Joshpalnagar', 'Jodhpur',
        'Rajasthan', '610020', '3317628');
INSERT INTO customer
VALUES (11, 'Sreenivasullu', 'Allu', 'Kotappakonda', 'Vijaywada',
        'Andhra Pradesh', '440011', '2745678');
INSERT INTO customer
VALUES (16, 'Pratheek', 'Sonpur', 'Abasnagar', 'Bangalore',
        'Karnataka', '540027', '2345675');
INSERT INTO customer
VALUES (15, 'Prakash', 'Kalburgi', 'Abids', 'Hyderabad',
        'Andhra Pradesh', '480046', '3425671');
INSERT INTO customer
VALUES (17, 'Atheek', 'Bhat', 'Golden beach road', 'Chennai',
        'Tamil Nadu', '580011', '6523873');
INSERT INTO customer
VALUES (18, 'Sanjay', 'Arora', 'Bandra west', 'Mumbai',
        'Maharashtra', '680025', '4317629');
INSERT INTO customer
VALUES (19, 'krishanamurthy', 'Hebbar', 'Mulund west',
        'Mumbai', 'Maharashtra', '680021', '6523874');
INSERT INTO customer
VALUES (20, 'Sofan', 'Charan', 'ChandaniChowk', 'Delhi',
        'Delhi', '280041', '4317623');



INSERT INTO Credit_card
VALUES ('4278652398675479', 15, 'Visa', '2020-11-20');
INSERT INTO Credit_card
VALUES ('6445126745786431', 12, 'Visa', '2019-10-19');
INSERT INTO Credit_card
VALUES ('4665198345786431', 16, 'Maestro', '2016-12-23');
INSERT INTO Credit_card
VALUES ('6527652398675479', 13, 'American Express', '2017-11-19');
INSERT INTO Credit_card
VALUES ('4327698658675479', 17, 'American Express', '2016-01-24');
INSERT INTO Credit_card
VALUES ('5436237845987698', 18, 'MasterCard', '2017-06-16');
INSERT INTO Credit_card
VALUES ('6922387765212351', 19, 'Visa', '2016-10-15');

INSERT INTO room_type
VALUES ('CK', 5000, 'king size', 'yes');
INSERT INTO room_type
VALUES ('CQ', 3000, 'queen size', 'yes');
INSERT INTO room_type
VALUES ('S1', 1000, 'single', 'no');
INSERT INTO room_type
VALUES ('D1', 2000, 'double', 'no');

INSERT INTO room
VALUES (100, 'S1', 'Luxury room', 'Lake view', '1', 'yes');
INSERT INTO room
VALUES (302, 'S1', 'Luxury room', 'Lake view', '2', 'no');
INSERT INTO room
VALUES (405, 'D1', 'Suits room', 'Mountain view', '4', 'no');
INSERT INTO room
VALUES (403, 'S1', 'Suits room', 'Mountain view', '4', 'yes');
INSERT INTO room
VALUES (505, 'CK', 'Classic Room King b', 'Mountain view', '5',
        'yes');
INSERT INTO room
VALUES (506, 'CQ', 'Classic room queen b', 'Mountain view', '5',
        'yes');
INSERT INTO room
VALUES (555, 'CK', 'Classic room king be', 'Mountain view', '3',
        'no');
INSERT INTO room
VALUES (511, 'CQ', 'Classic room queen', 'Mountain view', '5',
        'yes');

INSERT INTO room
VALUES (501, 'CQ', 'Classic room queen b', 'Mountain view', '5',
        'no');
INSERT INTO room
VALUES (410, 'CK', 'Classic room king b', 'Mountain view', '4', 'yes');


INSERT INTO agent
VALUES (6, 'Kabeer', ' Motel Paradise', 'Chandigarh');
INSERT INTO agent
VALUES (7, 'John', 'Go Holidays', 'Delhi');
INSERT INTO agent
VALUES (8, 'Husain', 'Travel Unlimited', 'Hyderabad');
INSERT INTO agent
VALUES (9, 'Suhas', 'Hotel Aryaas', 'Mumbai');
INSERT INTO agent
VALUES (10, 'Vikranth', 'Easy Royal Trip', 'Udupi');

INSERT INTO reservation
VALUES (31, 11, 511, 5100, NULL, '2013-10-13', 'yes', '2013-10-10', '2013-10-20', '2013-10-15', 6);
INSERT INTO reservation
VALUES (32, 12, 506, 8250, 'AOP716', NULL, 'yes', '2013-07-13', '2013-07-20', '2013-07-18', 8);
INSERT INTO reservation
VALUES (33, 13, 302, 4500, 'MCZ413', NULL, 'no', '2014-08-19', '2014-08-26', '2014-08-21', 9);
INSERT INTO reservation
VALUES (34, 14, 403, 5500, 'NQR224', '2012-09-20', 'yes', '2012-09-15', '2012-09-25', '2012-09-22', 7);
INSERT INTO reservation
VALUES (35, 16, 505, 6000, NULL, '2012-01-10', 'yes', '2012-01-08', '2012-01-27', '2012-01-25', 10);
INSERT INTO reservation
VALUES (36, 14, 501, 7430, 'ACZ413', NULL, 'no', '2013-03-01', '2013-03-15', '2013-03-13', 6);
INSERT INTO reservation
VALUES (37, 15, 302, 5000, 'PQR224', '2014-07-06', 'yes', '2014-07-04', '2014-07-20', '2014-07-16', 9);

INSERT INTO discount
VALUES (31, 7, 1000);
INSERT INTO discount
VALUES (35, 8, 900);
INSERT INTO discount
VALUES (32, 9, 1200);
INSERT INTO discount
VALUES (33, 6, 500);
INSERT INTO discount
VALUES (36, 10, 760);
INSERT INTO discount
VALUES (33, 6, 500);
INSERT INTO discount
VALUES (34, 9, 760);
INSERT INTO discount
VALUES (37, 10, 1300);

INSERT INTO preference
VALUES (1, 'Extra Blankets', 2, 1, 11);
INSERT INTO preference
VALUES (2, 'Extra Roll-Away Beds', 0, 2, 11);
INSERT INTO preference
VALUES (3, 'Extra Pillows', 1, 3, 11);
INSERT INTO preference
VALUES (4, 'Extra Toiletries', 0, 1, 14);
INSERT INTO preference
VALUES (5, 'Extra Roll-Away Beds', 0, 1, 15);
INSERT INTO preference
VALUES (6, 'Extra Pillows', 1, 2, 15);
INSERT INTO preference
VALUES (7, 'Extra Pillows', 3, 3, 15);
INSERT INTO preference
VALUES (8, 'Extra Toiletries', 2, 4, 15);
INSERT INTO preference
VALUES (9, 'Extra Blankets', 0, 1, 19);
INSERT INTO preference
VALUES (10, 'Extra Roll-Away Beds', 1, 2, 19);

# Retrieve all customer names who reserved their room in 1st to 3rd floor of the hotel but canceled their reservation.

SELECT c.CustId,
       res.RoomNo,
       c.First_name,
       c.Last_name
FROM Room r,
     Reservation res,
     Customer c
WHERE r.RoomFloor BETWEEN 1 AND 3
  AND R.RoomNo = res.RoomNo
  AND res.Cancel_Date IS NOT NULL
  AND res.custId = c.CustId;

# Retrieve customer names and bed type of customers who booked their rooms in the hotel and selected the cancel option
# as yes but did not cancel their reservation.

SELECT c.CustId,
       c.First_name,
       c.Last_name,
       rt.BedType
FROM Room r,
     Reservation res,
     Room_Type rt,
     Customer c
WHERE res.cancel_option = 'yes'
  AND res.Cancel_Date IS NULL
  AND rt.Room_type = r.RoomName
  AND r.RoomNo = res.RoomNo
  AND res.custId = c.CustId;

# Retrieve all customer names who canceled rooms in the hotel from 1st Jan 2012 to 31st Dec 2012 and
# from 1st Jan 2014 to 31st Dec 2014.

SELECT c.CustId,
       c.First_name,
       c.Last_name
FROM Customer c,
     Reservation res
WHERE res.Cancel_Date IS NOT NULL
  AND res.Cancel_Date BETWEEN '2012-01-01' AND '2012-12-31'
  AND res.custId = c.CustId
UNION
SELECT c.CustId,
       c.First_name,
       c.Last_name
FROM Customer c,
     Reservation res
WHERE res.Cancel_Date IS NOT NULL
  AND res.Cancel_Date BETWEEN '2014-01-01' AND '2014-12-31'
  AND res.custId = c.CustId;


# Retrieve the first name and the last name of customers who reserved rooms in the hotel from
# 1st August 2012 to 31st July 2013 in alphabetical order of their names.

SELECT c.CustId,
       c.First_name,
       c.Last_name,
       res.Reservation_Date
FROM Reservation res,
     Customer c
WHERE res.Reservation_Date BETWEEN '2012-08-01' AND '2013-07-13'
  AND c.CustId = res.custId
ORDER BY c.First_name, c.Last_name;

# Display the amount saved by customers, if the customer is provided with discounted reservation amount in comparison
# to the actual amount that would have cost the customer if price per night was considered from room_type table for
#staying in the hotel.

SELECT rt.pricePerNgt,
       DATEDIFF(res.Departure_date, res.Arrival_date)                            AS DaysStayed,
       ((res.Departure_date - res.Arrival_date) * rt.pricePerNgt)                AS ActualAmount,
       (((res.Departure_date - res.Arrival_date) * rt.pricePerNgt) - res.amount) AS AmountSaved,
       res.custId
FROM Reservation res,
     Room_Type rt,
     Room r
WHERE rt.Room_type = r.RoomName
  AND r.RoomNo = res.RoomNo;

# Display time since Mastercard has expired

SELECT ((DATEDIFF(curdate(), cc.Exp_Date) / 30) - FLOOR((DATEDIFF(curdate(), cc.Exp_Date) / 30))) * 30,
       FLOOR((((DATEDIFF(curdate(), cc.Exp_Date) / 30) / 12) -
              FLOOR(((DATEDIFF(curdate(), cc.Exp_Date) / 30) / 12)))) AS MONTHS,
       FLOOR(((DATEDIFF(curdate(), cc.Exp_Date) / 30) / 12))          AS YEARS
FROM Credit_Card cc
WHERE cc.CardType = 'Mastercard';


# ASSESSMENT 2 BEGINS HERE


INSERT INTO Credit_Card
VALUES ('2344765578987655', 15, 'Visa', '2002-02-20');

# Find average, min, max cost of each room.

SELECT res.RoomNo,
       AVG(res.amount) AS AVG_COST,
       MAX(res.amount) AS MAX,
       MIN(res.amount) AS MIN
FROM Reservation res
GROUP BY res.RoomNo;

# List customer who has made booking more than once [USING SET THEORY]

SELECT custId
FROM Customer;
#INTERSECT
SELECT custId
FROM Reservation
GROUP BY custId
HAVING COUNT(custId) > 1;

# For each credit card type that has at least two customers, retrieve the number of credit cards, number of rooms
# reserved and number of customers who have reserved at a cost higher than Rs 4000.

SELECT COUNT(cc.Cust_Id) AS NUMBER_OF_CUSTOMERS,
       cc.CardType,
       COUNT(res.RoomNo) AS ROOMS_RESERVED,
       count(cc.Card_no) AS NUMBER_OF_CARDS
FROM Credit_Card cc,
     Reservation res
WHERE cc.Cust_Id = res.custId
  AND res.amount > 4000
GROUP BY cc.CardType
HAVING count(cc.Cust_Id) >= 2;

# Find only the agent_id of each customer with an avg discount amount of over 1000.

SELECT r.custId,
       r.AgentID
FROM Discount d,
     Reservation r
WHERE d.ConfirmNo = r.ConfirmNo
GROUP BY r.custId, r.AgentID
HAVING AVG(d.DiscountAmount) > 1000;

# Retrieve room number, name, and number of customers staying in the room if there are more than one customers in a room.

SELECT COUNT(res.RoomNo) AS NUM_OF_CUSTOMERS,
       res.RoomNo,
       r.RoomName
FROM Reservation res,
     Room r
WHERE r.RoomNo = res.RoomNo
GROUP BY res.RoomNo
HAVING NUM_OF_CUSTOMERS > 1;

# Find number of customers present in each floor of the hotel.

SELECT roo.RoomFloor,
       COUNT(res.custId) AS NUM_OF_CUSTOMERS
FROM Room roo,
     Reservation res
WHERE res.RoomNo = roo.RoomNo
GROUP BY roo.RoomFloor
ORDER BY roo.RoomFloor;

# SELF DEFINED QUERY THAT DISPLAYS OUTPUT COMPRISING OF GROUP BY AND MAX FUNCTION, WITHOUT 'HAVING' CLAUSE.
# -> For each room that was reserved, find out the highest amount paid for that room.
SELECT res.RoomNo,
       MAX(res.amount) AS MAX_AMOUNT
FROM Reservation res
GROUP BY (res.RoomNo);