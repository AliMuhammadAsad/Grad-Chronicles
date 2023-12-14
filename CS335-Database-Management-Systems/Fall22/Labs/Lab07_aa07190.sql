--1--
select Orders.OrderID, OrderDate, ProductName from Orders
Inner Join [Order Details] as OD on Orders.OrderID = OD.OrderID
Inner Join Products on OD.ProductID = Products.ProductID

--2--
select Orders.OrderID, OrderDate, ProductName, ContactName as CustomerName  from Orders
Inner Join [Order Details] as OD on Orders.OrderID = OD.OrderID
Inner Join Products on OD.ProductID = Products.ProductID
Inner Join Customers on Customers.CustomerID = Orders.CustomerID

--3--
select Orders.OrderID, OrderDate, ProductName, CategoryName, ContactName from Orders
Inner Join [Order Details] as OD on Orders.OrderID = OD.OrderID
Inner Join Products on OD.ProductID = Products.ProductID
Inner Join Customers on Customers.CustomerID = Orders.CustomerID
Inner Join Categories on Categories.CategoryID = Products.ProductID

--4--
select Orders.OrderID, OrderDate, ProductName from Orders
Inner Join [Order Details] as OD on Orders.OrderID = OD.OrderID
Inner Join Products on OD.ProductID = Products.ProductID
Inner Join Categories on Categories.CategoryID = Products.CategoryID
where CategoryName = 'SeaFood'

--5--
select count(Quantity) as [Total Products] from [Order Details] where OrderID = 11070

--6--
select Suppliers.ContactName as SupplierName, count(*) as [No.ofProducts] from Suppliers
Inner Join Products on Products.SupplierID = Suppliers.SupplierID
group by Suppliers.ContactName
Order by [No.ofProducts]

--7--
select Suppliers.ContactName as [SupplierName], count(*) as [Products Supplied], CategoryName, AVG(UnitPrice) as [Average Unit Price], sum(UnitsInStock) as [Total Units in Stock] from Suppliers
Inner Join Products on Products.SupplierID = Suppliers.SupplierID
Inner Join Categories on Categories.CategoryID = Products.CategoryID
group by ContactName, CategoryName
order by [Products Supplied]

--8--
select Suppliers.ContactName as [Supplier Name] from Suppliers 
Inner Join Products on Products.SupplierID = Suppliers.SupplierID
group by Suppliers.ContactName
Having count(*) > 4

--9--
select Region.RegionDescription, count(*) as [No. of Employees] from Region
Inner Join Territories on Region.RegionID = Territories.RegionID
Inner Join EmployeeTerritories on Territories.TerritoryID = EmployeeTerritories.TerritoryID
Inner Join Employees on EmployeeTerritories.EmployeeID = Employees.EmployeeID
group by RegionDescription


--10--
select sum(UnitPrice * Quantity - Discount) as [Total Amount of Order ID 11070]  from [Order Details] where OrderID = 11070

--11--
select Orders.OrderID as [Order ID], sum(UnitPrice * Quantity - Discount) as [Total Amount]  from Orders
Inner Join [Order Details] as OD on OD.OrderID = Orders.OrderID
Group by Orders.OrderID

--12--
select Categories.CategoryName as [Category Name], count(*) as [No.ofProducts] from Categories
Inner Join Products on Products.CategoryID = Categories.CategoryID
Group by Categories.CategoryName

--13--
select Customers.ContactName as [Customer Name], S.ContactName as [Supplier Name], count(*) as [No. of Orders] from Customers
Inner Join Orders on Customers.CustomerID = Orders.CustomerID
Inner Join [Order Details] as OD on Orders.OrderID = OD.OrderID
Inner Join Products on OD.ProductID = Products.ProductID
Inner Join Suppliers as S on Products.SupplierID = S.SupplierID
Group by Customers.ContactName, S.ContactName

--14--
select (E.FirstName + E.LastName) as [Employee Name], YEAR(Orders.OrderDate) as [Year], count(*) as [No. of Orders] from Orders
Inner Join Employees as E on E.EmployeeID = Orders.EmployeeID
Group by E.FirstName + E.LastName, YEAR(OrderDate)

--15--
select Employees.ReportsTo as [Manager ID],(E.FirstName + E.LastName) as [Employee Name], count(*) as [No. of O.Orders] from Orders as O
Inner Join Employees as E on O.EmployeeID = E.EmployeeID
Inner Join Employees on E.EmployeeID = Employees.EmployeeID
Group by Employees.ReportsTo, (E.FirstName + E.LastName)

--16--
select Customers.ContactName as [Customer Name] from Customers
Left Outer Join Orders on Customers.CustomerID = Orders.CustomerID where Orders.OrderID is NULL

--17--
select OD.OrderID as [Order ID] from [Order Details] as OD
Inner Join Products on OD.ProductID = Products.ProductID
Inner Join Categories on Products.CategoryID = Categories.CategoryID where Categories.CategoryName = 'Meat/Poultry' or Categories.CategoryName = 'Dairy Products'

--18--
select Region.RegionDescription as [Region Name], count(*) as [No. of Employees] from Region
Inner Join Territories on Region.RegionID = Territories.RegionID
Inner Join EmployeeTerritories on Territories.TerritoryID = EmployeeTerritories.TerritoryID
Inner Join Employees on EmployeeTerritories.EmployeeID = Employees.EmployeeID
group by RegionDescription

--19--
select (FirstName + LastName) as [Employee Full Name], ContactName as [Customer Name] from Employees, Customers

--20--
select Shippers.CompanyName as [Shipper Name], count(*) as [Orders Fulfilled] from Shippers
Inner Join Orders on Shippers.ShipperID = Orders.ShipVia
Group by Shippers.CompanyName
