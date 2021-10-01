const list_of_users = []
const list_of_passwords = []
let count = 0

function pass_through() {
    let entered_user_email = document.getElementById("email").value
    let entered_password = document.getElementById("password").value
    let entered_cgpa = document.getElementById('cgpa').value

    list_of_users.push(entered_user_email)
    list_of_passwords.push(entered_password)

    localStorage.setItem('CGPA', entered_cgpa);
}

count = count + 1
document.getElementById('reg-id').innerHTML = count.toString()

function shortlist_students_bank_exam() {
    let cgpa = localStorage.getItem('CGPA')

    if (cgpa >= 9)
        document.getElementById('message').innerHTML +=
            "<br><div class='text-center'><h2>You're eligible to write the exam!</h2></div> "

    else
        document.getElementById('message').innerHTML +=
            "<br><div class='text-center'><h2>Sorry, you are ineligible</h2></div> "
}

function shortlist_students_railway_exam() {
    let cgpa = localStorage.getItem('CGPA')

    if (cgpa >= 8)
        document.getElementById('message').innerHTML +=
            "<br><div class='text-center'><h2>You're eligible to write the exam!</h2></div> "

    else
        document.getElementById('message').innerHTML +=
            "<br><div class='text-center'><h2>Sorry, you are ineligible</h2></div> "
}

function shortlist_students_ksrtc_exam() {
    let cgpa = localStorage.getItem('CGPA')

    if (cgpa >= 7.5)
        document.getElementById('message').innerHTML +=
            "<br><div class='text-center'><h2>You're eligible to write the exam!</h2></div> "

    else
        document.getElementById('message').innerHTML +=
            "<br><div class='text-center'><h2>Sorry, you are ineligible</h2></div> "
}
