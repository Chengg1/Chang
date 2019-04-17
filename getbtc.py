import requests
def GetBtc():
	api = "https://api.coindesk.com/v1/bpi/currentprice/USD.json"
	ret = requests.get(api)
	if(ret.status_code == 200):
		ret = ret.json()
		price = ret['bpi']['USD']['rate']
		#print(price)
		return price
	else:
		print("unable to call api this time")
		return False
if __name__ == '__main__':
	print(GetBtc()+' USD')