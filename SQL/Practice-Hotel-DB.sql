#  Display the customer names and discounted amount if every customer who has a discount code is given an additional 5%
#  discount on discount amount.

SELECT DISTINCT(c.First_name),
               (0.95 * d.DiscountAmount) AS New_Amount
FROM Discount d,
     Reservation r,
     Customer c
WHERE r.DiscountCode IS NOT NULL
  AND r.custId = c.CustId
  AND d.ConfirmNo = r.ConfirmNo;

#Retrieve all the customer names and credit card numbers who booked rooms in
# the hotel in increasing order of their arrival.

SELECT c.CustId,
       c.First_name,
       c.Last_name,
       cc.Card_no,
       r.Reservation_Date
FROM Reservation r,
     Credit_Card cc,
     Customer c
WHERE c.CustId = r.custId
  AND cc.Cust_Id = c.CustId
ORDER BY r.Reservation_Date;

#Find the customer names who reserved a room but did not specify any preference type.

SELECT DISTINCT c.CustId,
                c.First_name,
                c.Last_name
FROM Reservation r,
     Preference p,
     Customer c
WHERE c.CustId = r.custId
  AND r.custId = p.CustId
  AND p.PreferenceValue = 0;

# Find the total number of customers who stay in rooms with per night price being at most Rs.2000.

SELECT COUNT(c.CustId)
FROM Room_Type rt,
     Customer c,
     Reservation rs,
     Room r
WHERE c.CustId = rs.custId
  AND rs.RoomNo = r.RoomNo
  AND rt.pricePerNgt <= 2000
  AND r.RoomName = rt.Room_type;

# Modify the customer table to verify that the phone number of the customers would be having a minimum length of 7.

ALTER TABLE Customer
    ADD CHECK (phone LIKE '_______');

# Find the total number of unique agents who have not provided discount for any of the customers.

#For each room which was reserved by at least 2 distinct customers, find the room id and the number of customers
# who reserved it

SELECT r.RoomNo,
       COUNT(DISTINCT r.custId) AS No_of_Customers
FROM Reservation r,
     Room ro
WHERE ro.RoomNo = r.RoomNo
GROUP BY r.RoomNo
HAVING COUNT(r.custId) >= 2;

# Retrieve names, addresses & no.of rooms booked by customers who have more than one room booked

SELECT c.CustId,
       c.First_name,
       c.Last_name,
       COUNT(r.custId) AS No_Of_Rooms_Booked,
       c.Addrstreet,
       c.Addrcity,
       c.Addrstate,
       c.Addrzip
FROM Customer c,
     Reservation r
WHERE c.CustId = r.custId
GROUP BY r.custId
HAVING COUNT(r.custId) > 1;

# For every room, retrieve the room name, the number of customers stayed in the room and
# the average cost spent on reserving that room.

SELECT r.RoomNo,
       r.RoomName,
       COUNT(res.custId),
       AVG(res.amount) AS Avg_Amount
FROM room r,
     Reservation res
WHERE res.RoomNo = r.RoomNo
GROUP BY r.RoomNo;

# For every room reserved, retrieve the room number, total cost of the room, and number of customers
# in the room who have taken 'Extra Pillows'.

SELECT r.RoomNo,
       SUM(rt.pricePerNgt),
       COUNT(res.CustId)
FROM Reservation res,
     Preference p,
     Room_Type rt,
     room r
WHERE p.PreferenceType = 'Extra Pillows'
  AND p.CustId = res.custId
  AND r.RoomName = rt.Room_type
  AND res.RoomNo = r.RoomNo
GROUP BY r.RoomNo;

# Find the customerID and average discount amount of each customer,
# but keep the data of only those customers who have an agent_id over 9.

SELECT r.custId,
       AVG(d.DiscountAmount),
       count(custId)
FROM Reservation r,
     Discount d
WHERE d.ConfirmNo = r.ConfirmNo
  AND r.AgentID > 9
GROUP BY r.custId;

# Display the customer name having more
# than one card(Using set theory).

insert into Credit_Card
values ('6922387765212152', 19, 'MasterCard', '2016-10-15');

SELECT c.CustId,
       c.First_name,
       c.Last_name
FROM Credit_Card cc,
     Customer c
WHERE c.CustId = cc.Cust_Id
GROUP BY CustId
HAVING COUNT(cc.Cust_Id) > 1;

# Retrieve the customers who dont smoke

SELECT c.CustId,
       c.First_name,
       c.Last_name
FROM Room_Type rt,
     Customer c,
     Reservation r,
     room roo
WHERE rt.SmokeOpt = 'no'
  AND rt.Room_type = roo.RoomName
  AND roo.RoomNo = r.RoomNo
  AND r.custId = c.CustId;

# Retrieve the name and reservation cost of customers with highest reservation cost.


SELECT c.First_name,
       c.Last_name,
       c.CustId,
       r.amount
FROM Customer c,
     Reservation r
WHERE c.CustId = r.custId
  AND r.amount >= ALL (select amount from Reservation);

# Find the customer names who have reserved a room and are going to arrive last to the hotel

SELECT c.First_name,
       c.Last_name,
       c.CustId
FROM Customer c,
     Reservation r
WHERE r.Arrival_date >= ALL (SELECT Arrival_date from Reservation rr)
  AND c.CustId = r.custId;

# Write a query to find most preferred room by the customers

SELECT r.RoomNo
FROM Reservation r
GROUP BY r.RoomNo
HAVING COUNT(RoomNo) >= ALL
       (
           SELECT (COUNT(RoomNo))
           FROM Reservation
           GROUP BY RoomNo
       );


#Create a view called CRR containing customer name, room name, cost and arrival date, where the customer(FirstName) stayed in Room(RoomName) by reserving on
#Reservation(Cost , ArrivalDate).Now referencing only view CRR and table Customer,
#a)Write a SQL query that returns the address of the customer who arrived recently and whose reservation cost is high.

CREATE VIEW CRR AS
SELECT c.First_name,
       c.Last_name,
       r.amount,
       r.Arrival_date,
       roo.RoomName
FROM Customer c,
     Reservation r,
     Room roo
WHERE roo.RoomNo = r.RoomNo
  AND r.custId = c.CustId;

SELECT c.CustId,
       c.Addrstreet,
       CRR.Arrival_date
FROM CRR,
     Customer c
WHERE CRR.Arrival_date >= ALL (SELECT (CRR.Arrival_date) FROM CRR)
  AND CRR.First_name = c.First_name;