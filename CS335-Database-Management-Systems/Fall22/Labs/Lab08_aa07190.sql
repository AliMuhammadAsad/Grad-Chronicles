/* SubQueries are a must in this lab - Queries can still be run without sub queries but marks won't be given */

--1--
select Customers.ContactName as [Customer Name] from Customers where CustomerID not in (select Orders.CustomerID from Orders)
/* Without subqueries
select Customers.ContactName as [Customer Name] from Customers
Left Outer Join Orders on Customers.CustomerID = Orders.CustomerID where Orders.OrderID is NULL */

--2--
select OD.OrderID as [Order ID] from [Order Details] as OD where OD.ProductID in 
(select P.ProductID from Products as P where P.CategoryID in 
(select CategoryID from Categories where Categories.CategoryName = 'Meat/Poultry' or Categories.CategoryName = 'Dairy Products'))
--Without subqueries
/* select OD.OrderID as [Order ID] from [Order Details] as OD
Inner Join Products on OD.ProductID = Products.ProductID
Inner Join Categories on Products.CategoryID = Categories.CategoryID where Categories.CategoryName = 'Meat/Poultry' or Categories.CategoryName = 'Dairy Products'
*/

--3--
select OD.OrderID as [Order ID] from [Order Details] as OD where OD.ProductID not in 
(select P.ProductID from Products as P where P.CategoryID in 
(select CategoryID from Categories where Categories.CategoryName = 'Meat/Poultry' or Categories.CategoryName = 'Dairy Products'))

--4--
select TOP 1 EmployeeID as [Employee ID] from Employees where EmployeeID in
(select TOP 1 EmployeeID from Orders where YEAR(OrderDate) = 1997 order by OrderDate)
/* Without subqueries
select TOP 1 EmployeeID, OrderID, ORderDate from Orders where YEAR(OrderDate) = 1997 */

--5--
select * from Employees where ReportsTo in (select EmployeeID from Employees where ReportsTo is NULL)

--6--
select * from Employees where EmployeeID in 
(select EmployeeID from EmployeeTerritories where TerritoryID in 
(select TerritoryID from Territories where RegionID in 
(select RegionID from Region where RegionDescription = 'Western')))

--7--
select * from Employees where EmployeeID not in 
(select EmployeeID from EmployeeTerritories where TerritoryID in 
(select TerritoryID from Territories where RegionID in 
(select RegionID from Region where RegionDescription = 'Western')))

--8--
select * from Orders where EmployeeID in (select EmployeeID from Employees where EmployeeID not in 
(select EmployeeID from EmployeeTerritories where TerritoryID in 
(select TerritoryID from Territories where RegionID in 
(select RegionID from Region where RegionDescription = 'Western'))))

--9--
(select ContactName as [Name] from Customers where Country = 'USA') Union (select ContactName as [Name] from Suppliers where Country = 'USA')

--10--
select * from Products where UnitPrice = (select min(UnitPrice) from Products)
/* Without Subqueries
select TOP 1 * from Products order by UnitPrice*/

--11--
select * from Suppliers where SupplierID in
(select SupplierID from Products where CategoryID in
(select CategoryID from Categories where CategoryName = 'Beverages'))

--12--
select p.ProductName as [Product Name], p.CategoryID, (select count(distinct SupplierID) from Suppliers s where s.SupplierID in (select distinct SupplierID from Products where CategoryID = p.CategoryID)) as [No of Suppliers of that Category] from Products as p

--13--
Select (Employees.FirstName + Employees.LastName) as [Employee Name], DATEDIFF(Year, HireDate, GETDATE()) as [Time Employed in Years],
case
when DATEDIFF(Year, HireDate, GETDATE()) > 5 Then 3
when DATEDIFF(Year, HireDate, GETDATE()) <= 5 and DATEDIFF(Year, HireDate, GETDATE()) >= 3 Then 2
when DATEDIFF(Year, HireDate, GETDATE()) < 3 Then 1
End AS [Seniority Level]
from Employees

--14--
select ProductName as [Product Name], UnitPrice as [Price],
Case
When UnitPrice > 80 Then 'Costly'
When UnitPrice >= 30 and UnitPrice <= 80 Then 'Economical'
When UnitPrice < 30 Then 'Cheap'
End AS [Type]
from Products