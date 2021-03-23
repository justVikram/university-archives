create table job_designation 
(
    job_id varchar2(20) primary key,
    job_name varchar2(25) not null,
    shift varchar2(15) DEFAULT 'morning',
    years_of_exp int
);

desc job_designation;

INSERT INTO job_designation VALUES ('Jb101', 'Physician', 'Evening', 10); 

select * from job_designation;



INSERT INTO job_designation VALUES ('&job_id', '&job_name', '&shift', &years_ofexp);

select * from job_designation;

select * from job_designation where years_of_exp = 4;

drop table job_designation;

insert into job_designation
(job_id, job_name, years_of_exp)
values ('jb123', 'ABCD', 12);

DESC job_designation;

create table staff
(
    s_id varchar2(10) primary key,
    s_fname varchar2 (15) not null,
    s_lname varchar2 (15) not null,
    join_date date not null,
    phone_no numeric not null,
    job_id varchar2 (15) references job_designation (job_id) not null,
    salary int
);

insert into staff VALUES ('&s_id', '&s_fname', '&s_lname', '&join_date', &phone_no, '&job_id', &salary);
