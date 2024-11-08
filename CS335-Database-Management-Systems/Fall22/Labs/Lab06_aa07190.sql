--1--
select * from Customers

--2--
select OrderId, OrderDate, ShipCity, ShipCountry from Orders

--3--
select OrderId, OrderDate, CustomerId, ShipCountry = 'France' from Orders

--4--
select OrderId, OrderDate, CustomerID, ShipCountry from Orders where ShipCountry = 'France' or ShipCountry = 'Germany'

--5--
select OrderId, OrderDate, Freight, ShipCountry from Orders where ShipCountry in ('France', 'Germany') and Freight > 40

--6--
select OrderId, OrderDate, Freight, ShipName from Orders where ShipName = 'Quick-Stop'

--7--
select TitleOfCourtesy + ' ' + firstname + ' ' + lastname as EmployeeFullName, Title as EmployeeTitle from Employees

--8--
select OrderId, OrderDate, ShipName, ShipAddress, ShipCity, ShipCountry from Orders where ShipAddress like '%box%'

--9--
select OrderId, CustomerID from Orders where CustomerID like 'A%I'

--10--
select FirstName + ' ' + LastName as EmployeeName from Employees where DATEDIFF(year, HireDate, GETDATE()) > 10 

--11--
select *, DATEDIFF(day, orderdate, shippeddate) as OrderProcessTime from Orders

--12--
select * from Orders where DATEPART(month, OrderDate) = 6 

--13--
select * from Customers where Fax is NULL

--14--
select * from Products where QuantityPerUnit like '%boxes%'

--15--
select * from Suppliers where Fax is not NULL

--16--
select count(*) as CustomersWithoutFax from Customers where Fax is NULL

--17--
select count(*) as TotalSuppliers from Suppliers

--18--
select count(*) as TotalOrders_1997 from Orders where YEAR(orderdate) = 1997

--19--
select count(*) as TotalCustomers_UK from Customers where Country = 'UK'

--20--
select sum(UnitsInStock) as TotalAvailableItems from Products

--21--
select sum(UnitsInStock * UnitPrice) as Worth_All_Items from Products