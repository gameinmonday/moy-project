import json



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


from bs4 import BeautifulSoup as bs
import requests
import random
import re
import os
import csv
def get_headers():
    link = f'https://www.useragents.me/#most-common-desktop-useragents-json-csv'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36'
    }
    response = requests.get(link, headers=headers)
    soup = bs(response.text, 'lxml')
    res = soup.find_all('div', class_='table-responsive')[0].find_all('textarea')
    pattern = r'<textarea[^>]*>(.*?)<\/textarea>'
    ans = []
    for i in res:
        i = str(i)
        try:
            matches = re.findall(pattern, i)[0]
            ans.append(matches)
        except:
            continue
    return {'User-Agent': random.choice(ans)}

def download_image(url, folder_path, filename):
    # Make sure the folder exists
    os.makedirs(folder_path, exist_ok=True)

    # Send a HTTP request to the URL
    response = requests.get(url)

    # Check if the request was successful
    if response.status_code == 200:
        # Create the full path for the image
        file_path = os.path.join(folder_path, filename)

        # Write the image data to the file
        with open(file_path, 'wb') as file:
            file.write(response.content)

        print(f"Image successfully downloaded: {file_path}")
    else:
        print(f"Failed to download image. HTTP Status code: {response.status_code}")


def extract_movie_titles(file_path):
    movie_titles = []

    with open(file_path, 'r', encoding='utf-8') as file:
        reader = csv.DictReader(file, delimiter='\t')

        for row in reader:
            movie_titles.append(row['Title'])

    return movie_titles

# movie_titles = extract_movie_titles('IMDB-Movie-Data - IMDB-Movie-Data.tsv')

with open('links.tsv', 'r', encoding='utf-8') as file:
    movie_titles = [x.split('\t') for x in file.read().splitlines()]


# print(movie_titles)
# movie_titles_temp = movie_titles[10:11]
headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36'
    }
movie_titles = movie_titles[70:]
for t in range(len(movie_titles)):
    # movie_title = movie_titles[t][0]
    pattern = r'[^\w\s]'
    movie_title = re.sub(pattern, '', movie_titles[t][0])
    movie_url = movie_titles[t][1]
    movie_page = requests.get(movie_titles[t][1], headers=headers)
    movie_soup = bs(movie_page.content, 'html.parser')
    try:
        pattern = r'<script type="application/ld\+json">\s*(.*?)\s*</script>'
        info = re.findall(pattern, str(movie_soup))[0]
        image_url = re.findall(r'"image":"(https?://[^"]+)"', info)[0]
        folder = f'photos_for_dansers\{movie_title}'
        file_name = f"0.jpg"
        download_image(image_url, folder, file_name)
    except Exception as e:
        print(f'errot while parsing {movie_titles[t]} title photo: {e}')

    # link_text = movie_titles[t][1].replace(' ', '+')
    # h_link = f'https://beta.flim.ai/?ft={link_text}'
    # h_link_page = requests.get(h_link, headers=headers)
    # h_soup = bs(h_link_page.content, 'html.parser')
    # print(h_soup)

    try:
        tttt = re.findall(r'<script\s+id="__NEXT_DATA__"\s+type="application/json">(.*?)</script>', str(movie_soup))
        pattern = r'\"thumbnail\"\s*:\s*\{.*?\}'
        matches = re.findall(pattern, tttt[0], re.DOTALL)
        k = 0
        photo_set = set()
        for m in matches:
            m = m.split('\"thumbnail\"')[1][1:]
            m = json.loads(m)
            if m['height'] < m['width']:
                if k == 4:
                    break
                if m['url'] not in photo_set:
                    folder = f'photos_for_dansers\{movie_title}'
                    file_name = f"{k + 1}.jpg"
                    download_image(m['url'], folder, file_name)
                    photo_set.add(m['url'])
                    k += 1
        # for s in range(len(suitable)):
        #     folder = f'photos_for_dansers\{movie_titles[t][0]}'
        #     file_name = f"{s+1}.jpg"
        #     download_image(suitable[s], folder, file_name)

    except Exception as e:
        print(f'error with "{movie_titles[t]}" parsing horisontals: {e}')



