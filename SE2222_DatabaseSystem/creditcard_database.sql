create database labwork9;
use labwork9;

create table address(
	addressID int primary key,
    city varchar(50),
    streetname varchar(50),
    neighbourhood varchar(50),
    buildingnumber int,
    residencenumber int
);
    
create table customers(
	customerID int primary key,
    name varchar(50),
    surname varchar(50),
    phonenumber int,
    addressID int,
    foreign key(addressID) references address(addressID)
);

create table paymentinfo(
	payinfid int primary key,
    paymentmethod varchar(50),
    customerID int,
    foreign key(customerID) references customers(customerID)
);

create table creditcard(
    cardnumber int primary key,
    cardpassword int,
	customerID int,
    foreign key(customerID) references customers(customerID)
);


create table item(
	itemid int primary key,
    itemname varchar(50),
    description varchar(100),
    imagefilename varchar(50),
    price int
);    

create table menu(
	menuid int primary key,
    itemid int,
	foreign key(itemid) references item(itemid)
);
    
create table rate(
	rateid int primary key,
    rate int(5),
    customerID int,
	foreign key(customerID) references customers(customerID)
);

create table ordering(
	orderid int primary key,
    orderdate date,
    ordertime datetime,
    paymentinfo int,
    customerID int,
    foreign key(paymentinfo) references paymentinfo(payinfid),
	foreign key(customerID) references customers(customerID)
);


create table restaurant(
	restaurantid int primary key,
    paymentinfo int,
    addressID int,
    menuid int,
    rateid int,
    orderid int,
    foreign key(paymentinfo) references paymentinfo(payinfid),
    foreign key(addressID) references address(addressID),
    foreign key(menuid) references menu(menuid),
    foreign key(rateid) references rate(rateid),
    foreign key(orderid) references ordering(orderid)
);

create table review(
	rewid int primary key,
    review varchar(100),
    customerID int,
    rateid int,
    foreign key(rateid) references rate(rateid),
	foreign key(customerID) references customers(customerID)
);


insert into address(addressID, city, streetname, neighbourhood, buildingnumber, residencenumber) values (1, 'Ankara', 'A', 'B', 1, 2);
insert into address(addressID, city, streetname, neighbourhood, buildingnumber, residencenumber) values (2, 'Ankara', 'C', 'D', 1, 3);
insert into address(addressID, city, streetname, neighbourhood, buildingnumber, residencenumber) values (3, 'Ankara', 'E', 'F', 2, 4);
insert into address(addressID, city, streetname, neighbourhood, buildingnumber, residencenumber) values (4, 'Ankara', 'A', 'B', 2, 5);
insert into address(addressID, city, streetname, neighbourhood, buildingnumber, residencenumber) values (5, 'Ankara', 'A', 'B', 3, 6);

insert into customers(customerID, name, surname, phonenumber, addressID) values (1,'SelmaIrem','Ozdemir',111111111,1);
insert into customers(customerID, name, surname, phonenumber, addressID) values (2,'Selma','Oz',211111111,2);
insert into customers(customerID, name, surname, phonenumber, addressID) values (3,'Irem','Demir',311111111,3);
insert into customers(customerID, name, surname, phonenumber, addressID) values (4,'Selim','Oz',411111111,4);
insert into customers(customerID, name, surname, phonenumber, addressID) values (5,'Emir','Dem',511111111,5);

insert into paymentinfo(payinfid, paymentmethod, customerID) values (1,'card',1);
insert into paymentinfo(payinfid, paymentmethod, customerID) values (2,'card',2);
insert into paymentinfo(payinfid, paymentmethod, customerID) values (3,'card',3);
insert into paymentinfo(payinfid, paymentmethod, customerID) values (4,'card',4);
insert into paymentinfo(payinfid, paymentmethod, customerID) values (5,'card',5);

insert into creditcard(cardnumber, cardpassword, customerID) values(1,121212,1);
insert into creditcard(cardnumber, cardpassword, customerID) values(2,221212,2);
insert into creditcard(cardnumber, cardpassword, customerID) values(3,321212,3);
insert into creditcard(cardnumber, cardpassword, customerID) values(4,421212,4);
insert into creditcard(cardnumber, cardpassword, customerID) values(5,521212,5);

insert into item(itemid, itemname, description, imagefilename, price) values (1,'Hamburger','NormalBoy', 'aaa', 120);
insert into item(itemid, itemname, description, imagefilename, price) values (2,'Hamburger','NormalBoy', 'aaa', 120);
insert into item(itemid, itemname, description, imagefilename, price) values (3,'Hamburger','NormalBoy', 'aaa', 120);
insert into item(itemid, itemname, description, imagefilename, price) values (4,'Hamburger','NormalBoy', 'aaa', 120);
insert into item(itemid, itemname, description, imagefilename, price) values (5,'Hamburger','NormalBoy', 'aaa', 120);

insert into menu(menuid, itemid) values(1, 1);
insert into menu(menuid, itemid) values(1, 1);
insert into menu(menuid, itemid) values(1, 1);
insert into menu(menuid, itemid) values(1, 1);
insert into menu(menuid, itemid) values(2, 1);

insert into rate(rateid, rate, customerID) values (1,4,1);
insert into rate(rateid, rate, customerID) values (2,4,2);
insert into rate(rateid, rate, customerID) values (3,4,3);
insert into rate(rateid, rate, customerID) values (4,4,4);
insert into rate(rateid, rate, customerID) values (5,4,5);

insert into ordering(orderid, orderdate, ordertime, paymentinfo, customerID) VALUES (1, '2023-12-08', '2023-12-08 14:09:00', 1, 1);
insert into ordering(orderid, orderdate, ordertime, paymentinfo, customerID) VALUES (2, '2023-12-08', '2023-12-08 14:09:00', 2, 2);
insert into ordering(orderid, orderdate, ordertime, paymentinfo, customerID) VALUES (3, '2023-12-08', '2023-12-08 14:09:00', 3, 3);
insert into ordering(orderid, orderdate, ordertime, paymentinfo, customerID) VALUES (4, '2023-12-08', '2023-12-08 14:09:00', 4, 4);
insert into ordering(orderid, orderdate, ordertime, paymentinfo, customerID) VALUES (5, '2023-12-08', '2023-12-08 14:09:00', 5, 5);


insert into restaurant(restaurantid, paymentinfo, addressID, menuid, rateid, orderid) values (1,1,1,1,1,1);
insert into restaurant(restaurantid, paymentinfo, addressID, menuid, rateid, orderid) values (2,2,2,2,2,2);
insert into restaurant(restaurantid, paymentinfo, addressID, menuid, rateid, orderid) values (3,3,3,3,3,3);
insert into restaurant(restaurantid, paymentinfo, addressID, menuid, rateid, orderid) values (4,4,4,4,4,4);
insert into restaurant(restaurantid, paymentinfo, addressID, menuid, rateid, orderid) values (5,5,5,5,5,5);

insert into review(rewid, review, customerID, rateid) values (1,'good',1,1);
insert into review(rewid, review, customerID, rateid) values (2,'good',2,2);
insert into review(rewid, review, customerID, rateid) values (3,'good',3,3);
insert into review(rewid, review, customerID, rateid) values (4,'good',4,4);
insert into review(rewid, review, customerID, rateid) values (5,'good',5,5);
