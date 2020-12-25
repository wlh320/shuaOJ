import re
f = open('input')

cnt = 0
passport = {}
def check(passport, level=1):
    keys = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid']
    for key in keys:
        if key not in passport.keys():
            return 0
    return 1 if level == 1 else check2(passport)

def check2(passport):
    byr, iyr, eyr = passport['byr'], passport['iyr'], passport['eyr']
    if not (re.match(r'^\d{4}$', byr) and 1920<=int(byr)<=2002):
        return 0
    if not (re.match(r'^\d{4}$', iyr) and 2010<=int(iyr)<=2020):
        return 0
    if not (re.match(r'^\d{4}$', eyr) and 2020<=int(eyr)<=2030):
        return 0
    hgt = passport['hgt']
    if not (re.match(r'^\d+cm$', hgt) and 150 <= int(hgt[:-2]) <= 193):
        if not (re.match(r'^\d+in$', hgt) and 59 <= int(hgt[:-2]) <= 76):
            return 0
    hcl = passport['hcl']
    if not (re.match(r'^#[a-f0-9]{6}$', hcl)):
        return 0
    ecl = passport['ecl']
    if ecl not in ['amb' ,'blu', 'brn' ,'gry' ,'grn', 'hzl' ,'oth']:
        return 0
    pid = passport['pid']
    if not (re.match(r'^\d{9}$', pid)):
        return 0
    return 1

lines = f.readlines()
for line in lines:
    line = line.strip()
    if line == "":
        cnt += check(passport)
        passport = {}
    else:
        data = line.split(' ')
        for field in data:
            key, value = field.split(':')
            passport[key] = value
cnt += check(passport)
print(cnt)
passport = {}

cnt = 0
for line in lines:
    line = line.strip()
    if line == "":
        cnt += check(passport, level=2)
        passport = {}
    else:
        data = line.split(' ')
        for field in data:
            key, value = field.split(':')
            passport[key] = value
cnt += check(passport, level=2)
print(cnt)
