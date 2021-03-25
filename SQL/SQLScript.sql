drop table insure;
drop table insurance;
drop table Admission_Discharge_Patient;
drop table tests;
drop table ward;
drop table patient_prescription;
drop table patient;
drop table staff;
drop table job_designation;


create table job_designation(
job_id varchar(20) primary key not null,
job_name varchar(25) not null,
shift varchar(15),
year_of_experience int);


create table staff
(
s_id varchar(20) primary key not null,
s_fname varchar(20),
s_lname varchar(20),
date_of_emp date,
adrress varchar(60),
phone_no varchar(20),
job_id varchar(20) references job_designation(job_id),
salary int
);

create table patient(
p_id varchar(20) primary key not null,
p_fname varchar(20),
p_lname varchar(20),
address varchar(40),
phone_no varchar(20),
email_id varchar(20),
age int,
gender varchar(8));

create table patient_prescription(
prec_id varchar(20) primary key not null,
diagnosis varchar(20),
medicine varchar(20),
prec_date date,
s_id varchar(20),
p_id varchar(20),
foreign key (s_id) references staff(s_id),
foreign key (p_id) references patient(p_id));

create table ward(
w_no varchar(20) primary key not null,
no_of_beds int,
phone_no varchar(20),
s_id varchar(20) references staff(s_id)
);

create table tests(
t_id varchar(20) primary key not null,
t_name varchar(20),
t_date date,
s_id varchar(20) references staff(s_id),
prec_id varchar(20) references patient_prescription(prec_id));

create table Admission_Discharge_Patient(
id_no varchar(20) not null,
p_id varchar(20) not null,
primary key(id_no,p_id),
bed_no int,
w_no varchar(20),
date_admitted date,
date_discharged date,
remarks varchar(20));

create table insurance(
c_id varchar(20) not null primary key,
c_name varchar(20),
Contact_Fname varchar(20),
Contact_Lname varchar(20),
phone_no varchar(20));

create table insure(
p_id varchar(20) not null primary key,
c_id varchar(20),
foreign key (c_id) references insurance(c_id),
insuranc_type varchar(25),
amount int,
date_in date);

insert into job_designation values('jb01','physician','day','10');
insert into job_designation values('jb02','nurse','day','12');
insert into job_designation values('jb03','surgen','night','15');
insert into job_designation values('jb04','anthropologist',null,'05');
insert into job_designation values('jb05','ward boy','day','10');
insert into job_designation values('jb06','lab technician','day','18');
insert into job_designation values('jb07','radiologist','day','10');

insert into staff values('sf01','rohit','mishra','1998-02-10','17th cross5th main jaynagar bangalore','9886256641','jb01','40000');
insert into staff values('sf02','pooja','mehta','1995-01-23','vidyanagar hubli','9886257656','jb02','50000');
insert into staff values('sf03','anand','prakash','1998-04-15','banshankri 2nd phase bangalore','9900692198','jb03','55000');
insert into staff values('sf04','prashant','patil','1984-02-07','shirure park 2nd phase hubli','9900692199','jb01','35000');
insert into staff values('sf05','amit','kulkarni','1984-09-10','malleshwaran bangalore','9900692099','jb04','30000');
insert into staff values('sf06','shruthi','shettar','1976-02-27','gokulroad hubli','9944692099','jb02','40000');

insert into patient values('pt01','sonal','kulkarni','gokul road hubli','9844692099','sonal@gmail.com','23','female');
insert into patient values('pt02','saiprasad','bhat','madhura colony hubli','9844693099','prasad12@gmail.com','22','male');
insert into patient values('pt03','neha','patil','madhura colony hubli','7734693099','patil@rediff.com','25','female');
insert into patient values('pt04','anand','patil','maleshwaram 6th cross bangalore','6786534590','anand@rediff.com','25','male');

insert into ward values('wd01',2,'224651','sf06');
insert into ward values('wd02',2,'772934','sf01');
insert into ward values('wd03',2,'427654','sf02');
insert into ward values('wd04',3,'248403','sf06');


insert into patient_prescription values('pc01','malaria','luminal','2000-06-12','sf01','pt01');
insert into patient_prescription values('pc02','jaundice','coartem','1998-02-10','sf01','pt02');
insert into patient_prescription values('pc03','aids','ziagen','2005-05-05','sf05','pt01');
insert into patient_prescription values('pc04','fever','crocin plus','2002-12-15','sf03','pt04');

insert into tests values('ts01','hb rbc','2002-02-12','sf06','pc01');
insert into tests values('ts02','ct scan','2009-10-12','sf05','pc02');
insert into tests values('ts03','mri scan','2004-01-08','sf06','pc01');
insert into tests values('ts04','pathology','1999-09-08','sf03','pc03');

insert into admission_discharge_patient values('ad01','pt01','1004','wd01','2000-06-10','2000-07-20','fit and fine');
insert into admission_discharge_patient values('ad02','pt02','1005','wd01','1998-03-08','1999-04-30','psrtially fit');
insert into admission_discharge_patient values('ad03','pt03','1006','wd02','2000-01-01','2000-01-30','wound healed');
insert into admission_discharge_patient values('ad04','pt04','1007','wd03','1998-09-15','2000-11-10','wound nothealed');

insert into insurance values('cp01','icici lombard','punith','kumar','9990068756');
insert into insurance values('cp02','bharti axis','amit','kumar','999006887');
insert into insurance values('cp03','national','ravi','patil','778906887');
insert into insurance values('cp04','reliance','pooja','kamat','778909879');


insert into insure values('pt01','cp01','accidential','100000','2000-02-12');
insert into insure values('pt02','cp02','sick','20000','1999-03-10');
insert into insure values('pt03','cp04','stroke','200000','2004-11-15');
insert into insure values('pt04','cp04','paralysis','100000','2010-02-10');

 commit

use LocalDatabase;

select p_fname, p_lname from patient p, insure i where p.gender = 'female' and i.amount > 100000;

select p_fname from patient p, Admission_Discharge_Patient adp where p.p_id = adp.p_id
UNION
select p_fname from patient p, patient_prescription pp, tests t where p.p_id = pp.p_id AND pp.prec_id = t.prec_id;

#INTERSECT AND MINUS D.N.E.

select s_fname, salary from staff order by salary;

select s.s_fname, s.s_lname, s. salary, jd.year_of_experience from staff s, job_designation jd where s.job_id = jd.job_id order by jd.year_of_experience DESC;

select  avg(year_of_experience) from job_designation;

select count(distinct salary) distsalary from staff;

select count(distinct s_id) distinctpatients from ward where w_no = 'wd02';

#select MAX(jd.year_of_experience) lol, s.s_fname, s.s_lname from staff s, job_designation jd where s.job_id = jd.job_id group by s.s_lname;

select job_id, sum(salary) lol from staff group by job_id having sum(salary) > 50000;

select max(salary) from staff;

select avg(salary), s.job_id from staff s, job_designation jd where s.job_id = jd.job_id and jd.job_name = 'physician' group by s.job_id;