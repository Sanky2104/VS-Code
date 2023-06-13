from django.shortcuts import render
from django.shortcuts import render

# Create your views here.

list = []

def index(request):
    return render(request, 'trialapp/index.html', {})
    
def form(request):
    return render(request, 'trialapp/index.html', {
        "list": list
    })