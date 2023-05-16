from fastapi import FastAPI
from pydantic import BaseModel
app = FastAPI()
data = [
    {
        "id": 1,
        'name':'Harry Potter',
        'author':'J.K. Rowling'
    },
    {
        'id': 2,
        'name':'Regretting You',
        'author':'Colleen Hoover'
    }
]
global id
id=2
class Book(BaseModel):
    Name: str
    Author: str

@app.get("/books")
async def get_books():
    return data
@app.get("/books/id")
async def get_book(id: int):
    for book in data:
        if book['id']==id:
            return(book)
        return("message: book not found")
@app.post("/add_book")
async def add_book(book : Book):
    global id
    temp = {'id':id+1,'name':book.Name,'Author':book.Author}
    id=id+1
    data.append(temp)
    return(temp)