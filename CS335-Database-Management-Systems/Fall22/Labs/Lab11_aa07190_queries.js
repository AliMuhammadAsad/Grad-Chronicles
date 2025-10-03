/*
    This file was created through setting up a Connection with cloud Atlas as a MongoDB server. Therefore, I've removed all other information apart from the necessary immportant queries.
*/

// This sets up the database
db.students.insertMany([
    {"FirstName":"Hina",
    "LastName":"Baig","CGPA":3.5,"Major":"CS","Address":{"Street":"Puran Nagar","City": "Faisalabad","Province":"Punjab", "Country":"Pakistan"},"Phone":"3233389064","Courses":[{"course_id":"CS101","course_name":"Pfun","credits":4},{"course_id":"CS121","course_name":"OOP","credits":4}]},
    {"FirstName":"Karim", "LastName":"Khan","CGPA":3.2,"Major":"EE","Address":{"Street":" Off Nishter Road","City":
    "Karachi","Province":"Sindh","Country":"Pakistan"},"Phone":"9221-7733790","Courses":[{"course_id":"CH111","course_name":"PMAS","credits":3},{"course_id":"CS355","course_name":"DB","credits":4}]},
    {"FirstName":"Abid", "LastName":"Kasim","CGPA":2.9,"Major":"SDP","Address":{"Street":"ST-2, North Nazimabad,","City":
    "Karachi","Province":"Sindh","Country":"Pakistan"},"Phone":"9221-6678442","Courses":[{"course_id":"CS411","course_name":"AI","credits":3},{"course_id":"CS121","course_name":"OOP","credits":4},{"course_id":"CS411"
    ,"course_name":"AI","credits":3}]},
    {"FirstName":"Zainab", "LastName":"Karim","CGPA":3.1,"Major":"CS","Address":{"Street":"3-Khalid Centre, Wahdat Road","City":
    "Karachi","Province":"Sindh","Country":"Pakistan"},"Phone":"021-4412625","Courses":[{"course_id":"CS355","course_name":"DB","credits":4},{"course_id":"CS101","course_name":"Pfun","credits":4}]},
    {"FirstName":"Kumar", "LastName":"Rani","CGPA":2.8,"Major":"EE","Address":{"Street":"Malik Park Islam","City":"Lahore","Province":"Punjab","Country":"Pakistan"},"Phone":"042-7113284","Courses":[{"course_id":"CS101","course_name":"Pfun","credits":4}
    ]},
    {"FirstName":"Fahim", "LastName":"Alam","CGPA":3.7,"Address":{"Street":"Wilbert Squares","City": "Hunza","Province":"Gilgit-Baltistan","Country":"Pakistan"},"Phone":"359-99997"}
]);
    
// 1.Display All Students
db.students.find({})

// 2. Display All Students with CS Major
db.students.find({"Major": "CS"});

// 3. Display All Students with SDP Major
db.students.find({"Major":"SDP"});

// 4. Display all students from Karachi
db.students.find({"Address.City": "Karachi"});

// 5. Display all students not from Karachi
db.students.find({"Address.City": {$not:{$eq: "Karachi"}}});

// 6. All students having CGPA more than 3
db.students.find({"CGPA": {$gt : 3}});

// 7. All students having CGPA equal to 3.5
db.students.find({"CGPA": {$eq: 3.5}});

// 8. All students from Karachi with a CS Major
db.students.find({$and: [{"Address.City":"Karachi"}, {Major:"CS"}]});

// 9. Display all students for SDP and EE majors
db.students.find({$or: [{Major:"SDP"}, {Major:"EE"}]});

// 10. Only the first and last name of all Students
// Result: FirstName, LastName
db.students.find({}, {"FirstName":1, "LastName":1});

// 11. Only first name, last name and city for all students
// Result: FirstName, LastName, City
db.students.find({}, {"FirstName":1, "LastName":1, "Address.City":1});

// 12. First Name, Last Name, for students with CGPA greater than or equal to 3.5 without Object IDS
db.students.find({"CGPA":{$gte: 3.5}}, {"FirstName": 1, "LastName": 1, _id: 0});

// 13. Insert a student record (info in manual)
db.students.insertOne({"FirstName":"Fatima", "LastName":"Tariq", "Phone":"03124567891", "Address":{"Street":"Zainab Street Saddar", "City":"Karachi"}});

// 14. All students who do not have a Major property
db.students.find({"Major": {$exists:false}});

// 15. Insert using insertMany (info in manual)
db.students.insertMany([{"FirstName":"Zahid", "LastName":"Hakim", "Major":"CS"}, {"FirstName":"Ayesha", "LastName":"Asif"}, {"FirstName":"Faheem", "LastName":"Faiz", "Phone":"0213456789"}]);

// 16. Students who have taken the CS355 Course
db.students.find({"Courses.course_id":"CS355"});

// 17. Students who have not taken the CS355 Course
db.students.find({"Courses.course_Id": {$not : {$eq : "CS355"}}});

// 18. Increment CGPA of all students by 0.1
db.students.updateMany({}, {$inc : {"CGPA":0.1}});

// 19. Set CGPA of all students to 0.1
db.students.updateMany({}, {$set : {"CGPA":0.1}});

// 20. Introduce a new attribute Minor for students with the value CH
db.students.updateMany({}, {$set : {"Minor":"CH"}});

// 21. Add a new course for all students (info in manual)
db.students.updateMany({}, {$push: {"Courses": {"course_id":"CH101", "course_name":"Liberal Core", "credits":1}}});

// 22. Delete all students with CGPA less than 3.0
db.students.deleteMany({"CGPA" : {$lt : 3.0}});