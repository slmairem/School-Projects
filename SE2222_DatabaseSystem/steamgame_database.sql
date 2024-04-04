-- task1
create database steamgame; 
create table steamgamestats( 
	gameID int(6) unsigned auto_increment primary key,
	gamename varchar(50) not null,
	dailymaxplayers int,
	alltimemax int,
    developer varchar(50) not null,
    releasedate date,
    usdprice double
); 

-- task2
insert into steamgamestats values("1", "Don't Starve Together", "5966 ",  "67088", "Klei Entertainment", "2016-03-21" , "5.09");
insert into steamgamestats values("2", "Resident Evil 2", "1129 ",  "74153", "Capcom", "2019-01-25" , "9.99");
insert into steamgamestats values("3", "Hades", "5252",  "37586", "Supergiant Games", "2020-09-17" , "12.49");
insert into steamgamestats values("4", "Omori", "488",  "5640", "Omocat", "2020-12-25" , "11.99");
insert into steamgamestats values("5", "The Binding of Isaac: Rebirth", "25701",  "70701", "Edmund McMillen", "2014-11-04" , "14.99");

-- task3
alter table steamgamestats add tryprice double;

-- task4
set sql_safe_updates = 0;
update steamgamestats set tryprice = usdprice*9.2;

-- task5
delete from steamgamestats where developer="valve";

select * from steamgamestats;