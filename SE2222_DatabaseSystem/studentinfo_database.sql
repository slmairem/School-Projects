-- Q1
create database week05_labwork;
 
-- Q2
create table student(
	studentid int auto_increment primary key,
	studentname varchar(30) not null,
    studentsurname varchar(30) not null, 
    studentgender varchar(10) not null,
    countryoforigin varchar(30) not null,
    average int not null
);

-- Q3
create table studentlecture(
	recid int(10) auto_increment,
    coursecode int(10) not null,
    coursename varchar(20) not null,
    studentid int,
    primary key(recid),
    foreign key(studentid)
    references student(studentid) on delete cascade on update cascade
);

-- Q4
insert into student(studentname, studentsurname, studentgender, countryoforigin, average) values ( 'Aliyah', 'Luna', 'Female', 'USA', 65);
insert into student(studentname, studentsurname, studentgender, countryoforigin, average) values ( 'Emilio', 'Morales', 'Male', 'Spain', 82);
insert into student(studentname, studentsurname, studentgender, countryoforigin, average) values ( 'Rafael', 'Fuentes', 'Male', 'Argentina', 25);
insert into student(studentname, studentsurname, studentgender, countryoforigin, average) values ( 'Audrina', 'Martin', 'Female', 'USA', 98);
insert into student(studentname, studentsurname, studentgender, countryoforigin, average) values ( 'Josiah', 'Logan', 'Male', 'USA', 73);
insert into student(studentname, studentsurname, studentgender, countryoforigin, average) values ( 'Tara', 'Serrano', 'Female', 'USA', 60);
insert into student(studentname, studentsurname, studentgender, countryoforigin, average) values ( 'Trevon', 'Hess', 'Male', 'United Kingdom', 63);
insert into student(studentname, studentsurname, studentgender, countryoforigin, average) values ( 'Jayleen', 'Friedman', 'Female', 'USA', 36);
insert into student(studentname, studentsurname, studentgender, countryoforigin, average) values ( 'Antony', 'Estes', 'Male', 'Mexico', 80);
insert into student(studentname, studentsurname, studentgender, countryoforigin, average) values ( 'Sophie', 'Davila', 'Female', 'France', 77);
select*from student;

-- Q5
insert into studentlecture(coursecode, coursename, studentid) values (222, 'Arts', 4);
insert into studentlecture(coursecode, coursename, studentid) values (333, 'Physic', 3);
insert into studentlecture(coursecode, coursename, studentid) values (444, 'Language', 2);
select*from studentlecture;

-- Q6
alter table student add age int default '20';
select*from student;

-- Q7
set sql_safe_updates = 0;
update student set average = average+10;
select*from student;

-- Q8
update student set age=rand()*(30-18)+18;
select*from student;

-- Q9
delete from student where studentgender = 'Male';
select*from student;

-- Q10
select*from student where studentid in (select studentid from studentlecture where studentid=4);