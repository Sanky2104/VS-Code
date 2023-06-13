from django.urls import path
from . import views

app_name = "trialapp"

urlpatterns = [
    path("",views.index, name = "index")
]