--1--
CREATE VIEW [Summary of all Products] AS
select P.ProductName as [Product Name], ContactName as [Supplier Name], CategoryName as [Category], P.UnitPrice as [Price], count(OD.ProductID) as [No. of Orders], sum(OD.Quantity) as [Total qty sold] from Products as P
Inner Join Suppliers as S on P.SupplierID = S.SupplierID
Inner Join Categories as C on P.CategoryID = C.CategoryID
Inner Join [Order Details] as OD on P.ProductID = OD.ProductID
group by P.ProductName, S.ContactName, C.CategoryName, P.UnitPrice

Select * from [Summary of all Products]

drop view [Summary of all Products]

--2--
Create View [Summary of all Customers] as
select E.FirstName + ' ' + E.LastName as [Employee Name], Mango.FirstName + ' ' + Mango.LastName as [Manager Name] , DATEDIFF(YEAR, E.BirthDate, GETDATE()) as Age, DATEDIFF(Year, E.HireDate, GETDATE()) as [No. of Years with the company], count(OrderID) as [No. of Orders Processed]  from Employees as E
Inner Join Orders as O on E.EmployeeID = O.EmployeeID
Left Outer Join Employees as Mango on E.ReportsTo = Mango.EmployeeID
group by E.FirstName + ' ' + E.LastName, E.BirthDate, E.HireDate, Mango.FirstName + ' ' + Mango.LastName , Mango.ReportsTo

select * from [Summary of all Customers]

drop view [Summary of all Customers]

--3--
go
create Procedure OfferDiscount
@prod_id int, @discount float
as
begin
update Products
set UnitPrice = UnitPrice - (UnitPrice * @discount/100) where ProductID = @prod_id
end
begin
update [Order Details]
set UnitPrice = UnitPrice - (UnitPrice * @discount/100) where ProductID = @prod_id and OrderID in (select OrderID from Orders where ShippedDate is NULL)
end

exec OfferDiscount 51, 0.15

drop procedure OfferDiscount

--4--
go
create procedure DeleteEmployee
@e1 int
as begin
if (select ReportsTO from Employees where EmployeeID= @e1) is not null and (select count(Orders.OrderID) from Orders Inner Join Employees as E on E.EmployeeID = Orders.EmployeeID where E.EmployeeID = @e1) = 0
begin
delete EmployeeTerritories where EmployeeID = @e1
end
begin
update Employees
set ReportsTo = (select ReportsTo from Employees where EmployeeID = @e1) where ReportsTo = @e1
end
begin
delete Employees where EmployeeID = @e1
end
end


--5-- /* Might not work, Didn't work then at least xD */
go
create procedure CopyOrder
@OrderID int, @CustomerID nvarchar
as begin
	declare @NewOrderID int, @CurrentOrderDate datetime
	set @CurrentOrderDate = GETDATE()
	insert into Orders (CustomerID, OrderDate) values (@CustomerID, @CurrentOrderDate)
	set @NewOrderID = SCOPE_IDENTITY()
	insert into [Order Details] (OrderID, ProductID, UnitPrice, Quantity, Discount)
	select @NewOrderID, ProductID, UnitPrice, Quantity, Discount from [Order Details] where OrderID = @OrderID
end