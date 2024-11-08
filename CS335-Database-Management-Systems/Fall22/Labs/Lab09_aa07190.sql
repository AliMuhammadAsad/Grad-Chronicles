--1--
Set Identity_Insert Products On
insert into Products(ProductID, ProductName, CategoryID, UnitPrice)
values (2050,'Mountain Dew', 1, 10)
select * from Products

--2--
insert into Products(ProductID, ProductName, CategoryID, UnitPrice)
values (2051, 'Tea', (select CategoryID from Categories where CategoryName = 'Beverages'), 10)
select * from Products

--3--
update Products
set UnitPrice = UnitPrice * 1.25 where CategoryID in (select CategoryID from Categories where CategoryName = 'Beverages')

--4--
update [Order Details]
Set Discount = 0.2 where OrderID in (select OrderID from Orders where ShippedDate is NULL)

--5--
Set Identity_Insert Categories On
insert into Categories(CategoryName) values ('Drinks')
select * from Categories

--6--
Set Identity_Insert Products Off
insert into Products(ProductName, SupplierID, CategoryID, QuantityPerUnit, UnitPrice, UnitsInStock, UnitsOnOrder, ReorderLevel, Discontinued)
select ProductName, SupplierID, (select CategoryID from Categories where CategoryName = 'Drinks'), QuantityPerUnit, UnitPrice, UnitsInStock, UnitsOnOrder, ReorderLevel, Discontinued from Products where CategoryID in (
select CategoryID from Categories where CategoryName = 'Beverages')

--7--
update Products
set CategoryID = (select CategoryID from Categories where CategoryName = 'Drinks') where CategoryID  = (select CategoryID from Categories where CategoryName = 'Beverages')

--8--
select * from EmployeeTerritories where EmployeeID = (select EmployeeID from Employees where FirstName = 'Nancy' and LastName = 'Davolio')
select * from EmployeeTerritories where EmployeeID = (select EmployeeID from Employees where FirstName = 'Robert' and LastName = 'King')
delete from EmployeeTerritories where EmployeeID = (select EmployeeID from Employees where FirstName = 'Nancy' and LastName = 'Davolio')

insert into EmployeeTerritories(EmployeeID, TerritoryID)
select (select EmployeeID from Employees where FirstName = 'Nancy' and LastName = 'Davolio'), TerritoryID from EmployeeTerritories where EmployeeID = (select EmployeeID from Employees where FirstName = 'Robert' and LastName = 'King')

--9--
--a--
update employees
set reportsto =  (select employeeid from employees where FirstName= 'Robert' and LastName='King') where reportsto = (select employeeid from employees where FirstName= 'Steven' and LastName='Buchanan')

--b--
update orders
set employeeid = (select reportsto from Employees where FirstName='Steven' and LastName='Buchanan') where employeeid = (select employeeid from Employees where FirstName='Steven' and LastName='Buchanan')

--c--
delete EmployeeTerritories where EmployeeID = (select employeeid from Employees where FirstName='Steven' and LastName='Buchanan')

--d--
delete Employees where EmployeeID = (select employeeid from Employees where FirstName='Steven' and LastName='Buchanan')

--10--
delete Products where UnitPrice > 1000

--11--
delete Products where CategoryID = (select CategoryID from Categories where CategoryName = 'Seafood') and UnitsInStock < 5

--12--
/*delete Categories where CategoryID = (select CategoryID from Categories where CategoryID not in (select distinct CategoryID from Products))*/
delete from Categories where CategoryID not in (select distinct CategoryID from Products)

--13--
delete [Order Details] where OrderID = (select OrderId from Orders where CustomerID = (select CustomerID from Customers where ContactName = 'ALFKI'))
delete from Orders where CustomerID = 'ALFKI'

--14--
delete [Order Details] where orderID in (select OrderID from Orders where year(ShippedDate) = 1996 and MONTH(ShippedDate) = 8)
delete Orders where year(ShippedDate) = 1996 and month(ShippedDate) = 8