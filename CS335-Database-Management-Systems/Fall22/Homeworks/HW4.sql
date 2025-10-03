/*Q1 Orders Placed in July

Create a view that gives a summary of all the orders placed during July 1 - 10, 2012.
Result: OrderDate, OrderNumber, CustomerName (FirstName+‘ ’ + LastName),ProductName, SupplierName */

create view [order placed in july] as
select O.OrderDate, O.OrderNumber, (C.FirstName + ' ' + C.LastName) as [Customer Name], P.ProductName, S.CompanyName from [Order] as O, Customer as C, Product as P, Supplier as S, OrderItem
where O.CustomerID = C.ID and O.ID = OrderItem.OrderID and OrderItem.ProductID = P.ID and P.SupplierID = S.ID and O.OrderDate >= Convert(DateTime, '2012-07-01') and O.OrderDate <= Convert(DateTime, '2012-07-10');

/* --------------------------------------------------------------------------------------------------------------------------------

Q2 Customer Orders

Create a view that selects customers in the ascending order of their first name, the number of orders they have placed and their average order price. (Top 10 Results)
Result: CustomerFirstName, NoOfOrders, AveragePrice. */

create view [customer orders] as
select Top 10 C.FirstName, count(*) as NoOfOrders, avg(O.TotalAmount) as AveragePrice from Customer as C, [Order] as O where C.ID = O.CustomerID
group by C.FirstName

/* ---------------------------------------------------------------------------------------------------------------------------------

Q3 Summary of Ordered Products

Create a view that gives the summary of products ordered by customers in the ascending order of customer first name and product name. (Top 20 Results)
Result: Customer FirstName, ProductName, No of times Ordered, Total Quantity Ordered */

create view [ordered products summary] as 
select Top 20 C.FirstName, P.ProductName, count(OI.OrderID) as [No of time Ordered], sum(OI.Quantity) as [Total Quantity Ordered] from Customer as C, Product as P, [Order] as O, OrderItem as OI
where O.CustomerID = C.ID and OI.OrderID = O.ID and OI.ProductID = P.ID
group by C.FirstName, P.ProductName
Order by C.FirstName, P.ProductName

/* ---------------------------------------------------------------------------------------------------------------------------------

Q4 Opening Day

Create a view that selects the customers who have placed initial orders in the system.

Result: CustomerName
Note: These are customers who have placed orders on the very first day (i.e.min(Orderdate)). */

create view [opening day orders] as
select (C.FirstName + ' ' + C.LastName) as [CustomerName] from Customer as C, (select min(OrderDate) as [OrderDate] from [Order]) as [InitialOrders], [Order] as O_compare where O_compare.CustomerID = C.ID and O_compare.OrderDate = [InitialOrders].[OrderDate]

/* ---------------------------------------------------------------------------------------------------------------------------------

Q5 No Orders 2

Delete all the customers who have not placed any orders. */

Delete from Customer where ID not in (select CustomerID from [Order])

/* ---------------------------------------------------------------------------------------------------------------------------------

Q6 Cheapest Products 2

Create a view that gives the cheapest product in the database.
Result: ProductName, UnitPrice */

create view [cheapest products] as
select ProductName, UnitPrice from Product where UnitPrice = (select min(UnitPrice) from Product) 

/* ---------------------------------------------------------------------------------------------------------------------------------

Q7 Supply More than 3

Create a view that gives all the suppliers who supply more than 3 products.
Result: SupplierName (i.e. CompanyName), NoOfProducts */

create view [supply more than 3] as
select S.CompanyName as SupplierName, count(P.ID) as NoOfProducts from Supplier as S, Product as P where P.SupplierID = S.ID
group by S.CompanyName having count(P.ID) > 3

/* ---------------------------------------------------------------------------------------------------------------------------------

Q8 New Order

Insert a new order with given values:
OrderNumber:610000
Customerid: 77
TotalAmount: 139.5

Products in this order:
ProductId : 10
Unit Price: 31
Quantity: 3

ProductId : 14
Unit Price: 23.25
Quantity: 2 */

Insert into [Order](OrderNumber, CustomerID, TotalAmount) values(610000, 77, 139.5)

Insert into OrderItem(OrderID, ProductID, UnitPrice, Quantity) values((select max(ID) from [Order]), 10, 31, 3)

Insert into OrderItem(OrderID, ProductID, UnitPrice, Quantity) values ((select max(ID) from [Order]), 14, 23.25, 2)

/* ---------------------------------------------------------------------------------------------------------------------------------

Q9 Copying Order

Make a copy of Order having OrderNumber '543194' with a new OrderNumber (max(OrderNumber)+1) with current date as order date
and assign the new order to customerID '90'. While making copy of an Order, all products in that order will also be copied. */


Insert into [Order](OrderDate, OrderNumber, CustomerID, TotalAmount) values (GetDate(), (select max(OrderNumber) + 1 from [Order]), 90, (select TotalAmount from [Order] where OrderNumber = 543194))

Insert into OrderItem select (select ID from [Order] where OrderNumber = (select max(OrderNumber) from [Order])), ProductID, UnitPrice, Quantity from OrderItem where OrderID = (select ID from [Order] where OrderNumber = 543194)


/* ---------------------------------------------------------------------------------------------------------------------------------

Q10 Delete Orders

Delete all orders placed by Customer ID '10' from the system. */

Delete from OrderItem where OrderID in (select ID from [Order] where CustomerID = 10)
Delete from [Order] where CustomerID = 10

/* ---------------------------------------------------------------------------------------------------------------------------------

Q11 Price Increase 

Increase price of all products supplied by the supplier 'Tokyo Traders' by 10%. */

Update Product
set UnitPrice = UnitPrice * 1.1 where SupplierID in (select ID from Supplier where CompanyName = 'Tokyo Traders')

/* ---------------------------------------------------------------------------------------------------------------------------------

Q12 Supplier Acquisition

Supplier Company Bigfoot Breweries has recently acquired New Orleans Cajun Delights and all their products now belong to Bigfoot Breweries.
Also, as part of the change New Orleans Cajun Delights no longer exists.
Update your database to reflect this change. */

Update Product
set SupplierID = (select ID from Supplier where CompanyName = 'Bigfoot Breweries') where SupplierID = (select ID from Supplier where CompanyName = 'New Orleans Cajun Delights')

Delete from Supplier where CompanyName = 'New Orleans Cajun Delights'






