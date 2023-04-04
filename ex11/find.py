import requests
import sys

def get_abilities(poke):
    print(f'Name: {poke["name"].capitalize()}')
    print(f'Abilities:')
    for i in poke['abilities']:
        print(f"- " + str(i['ability']['name'].capitalize()))

try:
    pokemon = str(input('Enter the name of a Pokemon: '))
except (KeyboardInterrupt, EOFError):
    print("")
    sys.exit()

api = f'https://pokeapi.co/api/v2/pokemon/{pokemon.lower() }'

try:
    res = requests.get(api)
    if res.status_code != 200:
        print(f"Error:", res.status_code + "not found")
    else:
        poke= res.json()
        get_abilities(poke)
except:
    print("Error fetching data from the API")