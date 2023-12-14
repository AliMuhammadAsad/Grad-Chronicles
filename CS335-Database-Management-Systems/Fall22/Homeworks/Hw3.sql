/*Intro To Schema:
An organization wants to store its employees' data using Information Systems. The system stores information abouteach worker with their respective departments.
The system also stores information when a certain designation is assigned to a respective person. 
It is important to mention that system can store future designations as well: a designation can be affected in the future as well. 
The Bonus entity stores any bonus awarded to any employee.*/

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

-- Q1: List all records of worker entries:
select * from Worker

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q2 List number of employees in each department
select Dept_Name, count(Worker_ID) as No_Of_Workers from Department
Inner Join Worker on Worker.Dept_ID = Department.ID
group by dept_name

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q3 Display the employement history of 'Malik Zain' - list all his designations and keep his current designation on top
select (First_Name + ' ' + Last_Name), D.Title, T.Affected_From  from Worker 
Inner Join Title as T on Worker.Worker_ID = T.Worker_Ref_ID 
Inner Join Designation as D on T.Designation_ID = D.ID
where (First_Name + Last_Name = 'MalikZain')
group by (First_Name + ' ' + Last_Name), D.Title, T.Affected_From

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q4 Total Salary of Admin: Display total salary of all workers belonging to 'Admin' Department
select Dept_Name, sum(salary) from Department as D
Inner Join Worker on D.ID = Worker.Dept_ID where Dept_Name = 'Admin'
group by dept_name

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q5 Salary and Department Name: List all workers with their salaries and department names
select First_Name, Last_Name, Salary, isnull(Dept_Name, 'No Department') from Worker
Left Outer Join Department as D on Worker.Dept_ID = D.ID

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q6 Years of Service: List all workers with their joining dates and total number of years in service with the company
select First_Name, Last_Name, (select Convert(Date, Joining_Date)), DateDiff(Year, Joining_Date, GetDate()) as Years from Worker

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q7 No designation and no department: List all workers who do not have any designation and are not assigned to any department
select Worker_Id, First_Name, Last_Name, Joining_Date from Worker
Left outer Join Title as T on Worker.Worker_Id = T.Worker_Ref_Id 
where Worker.Dept_Id is null and T.Designation_Id is Null

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q8 Highest Salary of Department
select Dept_name, Max(Salary) from Department as D
Inner Join Worker as W on D.ID = W.Dept_ID
group by Dept_name

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q9 Current Designation
select First_Name, Last_Name, Title, max(Affected_From) from Worker, Title, Designation where Worker.Worker_Id = Title.Worker_Ref_Id and Title.Designation_Id = Designation.Id and Affected_From in (select max(Affected_From) from Title as T where T.Worker_Ref_Id = Title.Worker_Ref_Id)
group by First_Name, Last_Name, Title
order by First_Name

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q10 Not Assigned Employees - Departments without  employees
select Dept_Name from Department as D
Left Outer Join Worker as W on D.Id = W.Dept_ID where W.Dept_Id is null
group by Dept_Name

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q11 Same day Joining - Workers joined on the same date - new employees first
select First_Name, Last_Name, convert(date, Joining_Date) from Worker where convert(date, Joining_Date) in (select convert(date, Joining_Date) from Worker as W where Worker.Worker_Id <> W.Worker_Id )
order by convert(date, Joining_Date) desc

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q12 No Bonus - Workers who didn't get any bonuses
select First_name, last_name, joining_date from Worker
where worker_id not in (select worker_ref_id from Bonus)
order by first_name

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q13 More than average salaries
select Worker.First_Name, Worker.Last_Name, Department.Dept_Name, Worker.Salary from Worker, Department, (select Dept_Id, avg(salary) as S from Worker group by dept_id) as Salary_Table where Salary_Table.Dept_Id = Department.Id and Worker.Salary > Salary_Table.S and Salary_Table.Dept_Id = Worker.Dept_Id

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q14 Total Bonus - Workers and the total Bonus they received
select Worker.First_Name, Worker.Last_Name, isnull(sum(B.Bonus_Amount), 0) from Worker
Left Outer join Bonus as B on Worker.Worker_Id = B.Worker_Ref_Id
group by First_Name, Last_Name
order by sum(B.Bonus_Amount) desc

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q15 More than one bonus
select First_Name, D.Dept_Name, year(B.Bonus_Date), count(B.Worker_Ref_Id) from Worker
Inner Join Department as D on Worker.Dept_Id = D.Id
Inner Join Bonus as B on Worker.Worker_Id = B.Worker_Ref_Id
group by First_Name, D.Dept_Name, B.Bonus_Date having count(B.Worker_Ref_Id) > 1

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q16 Second Highest Salary
select top 2 First_Name, Last_Name, Dept_Name, Salary from Worker, Department where Worker.Dept_Id = Department.Id and Salary < (select max(salary) from Worker) order by Salary desc

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

--Q17 Bonus in 2017 but not in 2018
select First_Name, Last_Name, D.Dept_Name, sum(B.Bonus_Amount) from Worker, Department as D, Bonus as B 
where Worker.Dept_Id = D.Id and Worker.Worker_Id = B.Worker_Ref_Id and Worker_Id in 
(select Worker_Id from Worker, Bonus where Worker.Worker_Id = Bonus.Worker_Ref_Id and year(Bonus_Date) = '2017' and Worker.Worker_Id not in (select Worker_Id from Worker, Bonus where Worker.Worker_Id = Bonus.Worker_Ref_Id and year(Bonus_Date) = '2018'))
group by First_Name, Last_Name, Dept_Name










