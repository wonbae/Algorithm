#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'getTotalGoals' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING team
#  2. INTEGER year
#

def getTotalGoals(team, year):
    import requests
    import json
    # url = "https://jsonmock.hackerrank.com/api/football_matches?year=2011&team1=Barcelona&page=2"
    url = "https://jsonmock.hackerrank.com/api/football_matches"
    # url = "https://jsonmock.hackerank.com/api/football_matches?year=" + str(year) + "&team1=" + team + "&page=2"
    params = {'year' : year, 'team1' : team}
    pages = requests.get(url, params).json()
    
    # print(pages)
    print(params)
    cnt = 0

    for page in range(1, pages['total_pages']+1):
        params['page'] = page
        tmp = requests.get(url, params).json()
        # print(tmp)
        
        for data_per_page in tmp['data']:           
            if data_per_page['team1'] == team:
                cnt+=int(data_per_page['team1goals'])
               
    del params['team1']
    params['team2'] = team
    print(params)
    pages = requests.get(url, params).json()
    for page in range(1, pages['total_pages']+1):
        params['page'] = page
        tmp = requests.get(url, params).json()
        for data_per_page in tmp['data']:
            if data_per_page['team2'] == team:
                cnt+=int(data_per_page['team2goals']) 
    return cnt

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    team = input()

    year = int(input().strip())

    result = getTotalGoals(team, year)

    fptr.write(str(result) + '\n')

    fptr.close()
