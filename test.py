import re
filenames = [
"1058D2-A.cpp",
"1058D2-C.cpp",
"1069A.cpp",
"122A-luckydivsion.cpp",
"2132C1-cunningsell.cpp",
"1A.cpp",
"2094B-bobritto.cpp",
"A_Another_Popcount_Problem.cpp"
]
for f in filenames:
    m = re.match(r"^(\d+)(?:[A-Za-z0-9]+-)?([A-Z][0-9]?)(?:-.*)?\.cpp$", f)
    if m:
        print(f"{f}: {m.group(1)} {m.group(2)}")
    else:
        # fallback for no hyphen like 1069A
        m2 = re.match(r"^(\d+)([A-Z][0-9]?)(?:-.*)?\.cpp$", f)
        if m2:
             print(f"{f}: {m2.group(1)} {m2.group(2)}")
        else:
             print(f"{f}: NO MATCH")
