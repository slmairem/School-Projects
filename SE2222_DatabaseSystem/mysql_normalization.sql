USE `Week11Lab`;

-- Question 1
-- 1.a
select*from student
join exam on exam.StudentID = student.StdID
join course on exam.CID = course.CID
where course.Year=2015 and course.CourseName= "Geology" and exam.ExamType = "Midterm";


-- 1.b
-- they don't do the same thing, 
-- natural join merges all matching columns and data types, have columns with duplicated by name but
-- inner join operates specific conditions

select * from student
natural join course
natural join exam
where exam.Year = 2015 and course.CourseName= "Geology" and exam.ExamType = "Midterm";


-- Question 2
select distinct course.CID, course.CourseCode, course.CourseName, professor.ProfName, professor.ProfLastname from course
join professor 
on course.InstructorID = professor.ProfessorID
left join exam
on course.CID = exam.CID
where course.Year=2015 and course.Semester=1;

-- Question 3
select * from club
right join student
on club.ClubID = student.ClubMembership;

-- Question 4
insert into club (ClubID, ClubName, ClubChairman, Budget)
values (26 ,'Butterfly Catchers', NULL, 622000);

select*from student
left join club on student.ClubMembership = club.ClubID
union select*from student
right join club on student.ClubMembership = club.ClubID;

-- Question 5
select * from student
join department on student.Department = department.DeptID
join course on course.Department = department.DeptID
join professor on professor.ProfessorID = course.InstructorID
join exam on exam.CID = course.CID
join club on club.ClubID = student.ClubMembership

into outfile "university_denormalized.csv";
