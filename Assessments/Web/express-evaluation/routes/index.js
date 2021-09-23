require('dotenv').config()
const express = require('express');
const router = express.Router();
const mysql = require('mysql2')

// *Specifying database credentials
const con = mysql.createConnection({
    host: process.env.db_host,
    user: process.env.db_user,
    password: process.env.db_password,
})

// *Connect to database
con.connect(function (err) {
    if (err)
        throw err
    console.log('Connected to MySQL server (8.0.26)')
    const use_db = 'use delta'
    con.query(use_db, function (err) {
        if (err)
            throw err
        console.log('Using database: Delta')
    })
})

// Make a get request
function make_get_request(path, view, retrieve_query) {
    router.get(path, (request, response) => {
        if (retrieve_query) {
            con.query(retrieve_query, (err, result) => {
                if (err)
                    throw err
                console.log('Values have been fetched!')
                response.render(view, {result: result})
            })
        } else
            response.render(view)
    })
}

// Make a post request from student login page
function make_post_request_student(path, view) {
    router.post(path, (request, response) => {
        let email = request.body.email
        let password = request.body.password
        let validate_query = mysql.format("SELECT * FROM student_login WHERE username = ? AND password = ?;",
            [email, password])
        con.query(validate_query, (err, valid_credential) => {
            if (valid_credential.length > 0) {
                let retrieve_query = 'SELECT distinct(course_name), faculty_name FROM students;'
                con.query(retrieve_query, (err, result) => {
                    if (err)
                        throw err
                    response.render(view, {result: result})
                })
            } else
                response.send('Invalid')
        })
    })
}

function make_post_request_admin(path, view) {
    router.post(path, (request, response) => {
        let email = request.body.email
        let password = request.body.password
        let validate_query = mysql.format("SELECT * FROM admin_login WHERE username = ? AND password = ?;",
            [email, password])
        con.query(validate_query, (err, valid_credential) => {
            if (valid_credential.length > 0) {
                let retrieve_query = 'SELECT * from students;'
                con.query(retrieve_query, (err, result) => {
                    if (err)
                        throw err
                    response.render(view, {result: result})
                })
            } else
                response.send('Invalid')
        })
    })
}

// *FUNCTION CALLS

// GET home page
make_get_request('/', 'index')

// GET admin login page
make_get_request('/admin-login', 'admin-login')

// GET user login page
make_get_request('/user-login', 'user-login')

// Validate login credentials for admin and redirect to admin home
make_post_request_admin('/admin-home', 'admin-home')

// Validate login credentials for student and redirect to user home
make_post_request_student('/user-home', 'user-home')

module.exports = router;
