import requests
import json

def fetch_gps_data(latitude_south, longitude_west, latitude_north, longitude_east):
	overpass_url = "http://overpass-api.de/api/interpreter"
	overpass_query = f"""
	[out:json];
	node
		["aeroqay"="areodrome"]
		({latitude_south}, {longitude_west},{latitude_north}, {longitude_east});
	out body;
	"""

	response = requests.get(overpass_url, params={'data': overpass_query})

	if response.status_code == 200:
		data = repsonse.json()
		return data
	else:
		print(f"Error fetching data: {response.status_code}")
		return None

def save_gps_data_to_json(data, output_file):
	with open(output_file, 'w') as file:
		json.dump(data, file, indent=4)

if __name__ == "__main__":

	latitude_south = 38.5
	longitude_west = -77.5
	latitude_north = 39.5
	longitude_east = -76.5

	data= fetching(latitude_south, longitude_west, latitude_north, longitude_east)
	if data:
	save_gps_data_to_json(data, "gps_data.json")
	print("GPS data saved to gps_data.json")