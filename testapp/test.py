from flask import Flask, request, render_template
import sqlite3

app = Flask(__name__)


@app.route("/add_attendance", methods=["GET", "POST"])
def add_attendance():
    if request.method == "POST":
        student_id = request.form["student_id"]
        schedule_date = request.form["schedule_date"]
        subject_id = request.form["subject"]
        attendance = request.form["attendance"]

        conn = sqlite3.connect("test")
        cursor = conn.cursor()
        cursor.execute(
            "INSERT INTO Посещения (студент_id, расписание_id, посещение) VALUES (?, ?, ?)",
            (student_id, schedule_date, attendance),
        )
        conn.commit()
        conn.close()
        return "Данные успешно добавлены"
    else:
        conn = sqlite3.connect("test")
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM Студенты")
        students = cursor.fetchall()
        cursor.execute("SELECT * FROM Занятия")
        subjects = cursor.fetchall()
        print(subjects)
        conn.close()
        return render_template(
            "add_attendance.html", students=students, subjects=subjects
        )


if __name__ == "__main__":
    app.run(debug=True)
