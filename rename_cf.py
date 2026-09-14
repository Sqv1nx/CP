import os
import re
import urllib.request
import time

cf_dir = "/home/sqv/Coding/CP/CF"

for filename in os.listdir(cf_dir):
    if not filename.endswith(".cpp"): continue
    
    m = re.match(r"^(\d+)(?:[A-Za-z0-9]+-)?([A-Z][0-9]?)(?:-.*)?\.cpp$", filename)
    if not m:
        m = re.match(r"^(\d+)([A-Z][0-9]?)(?:-.*)?\.cpp$", filename)
    
    if not m:
        continue
        
    cid = m.group(1)
    idx = m.group(2)
    
    url = f"https://codeforces.com/contest/{cid}/problem/{idx}"
    try:
        req = urllib.request.Request(url, headers={'User-Agent': 'Mozilla/5.0'})
        with urllib.request.urlopen(req) as response:
            html = response.read().decode('utf-8')
            title_match = re.search(r'<div class="title">\s*[A-Z][0-9]?\.\s*(.*?)\s*</div>', html)
            if title_match:
                name = title_match.group(1)
                clean_name = re.sub(r'[^a-zA-Z0-9]+', '_', name).strip('_')
                new_filename = f"{idx}_{clean_name}.cpp"
                
                old_path = os.path.join(cf_dir, filename)
                new_path = os.path.join(cf_dir, new_filename)
                
                if old_path != new_path:
                    print(f"Renaming {filename} -> {new_filename}")
                    os.rename(old_path, new_path)
            else:
                print(f"Title not found for {filename} at {url}")
    except Exception as e:
        print(f"Error fetching {url}: {e}")
    time.sleep(0.3)
