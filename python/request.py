import requests
url = 'https://json.org/example.html'
repsonse = requests.get(url)
print(repsonse.text)