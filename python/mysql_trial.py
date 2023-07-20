import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  password="Bobo2104@"
)

#print(mydb)

mycursor = mydb.cursor()
mycursor.execute("select * from mydb.flights")
myresult = mycursor.fetchall()
for x in myresult:
    print(x)

