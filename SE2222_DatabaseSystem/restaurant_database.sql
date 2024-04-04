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