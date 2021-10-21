import numpy
import scipy
import operator
import json
from collections import defaultdict, Counter

publications = defaultdict(lambda: defaultdict(int))
citations = defaultdict(lambda: defaultdict(int))
pubnumbs = []
names = defaultdict()
actual_year = 2019


def IF(year, publicationNumber):
    cit = citations[publicationNumber][str(
        int(year) - 1)] + citations[publicationNumber][str(int(year) - 2)]
    pub = publications[publicationNumber][str(
        int(year) - 1)] + publications[publicationNumber][str(int(year) - 2)]

    return cit / pub


def getif(x):
    return (-IF(actual_year, x), names[x])


n = int(input())
p = json.loads(input())

for publication in p["publications"]:
    names[publication["publicationNumber"]] = publication["publicationTitle"]
    pubnumbs.append(publication["publicationNumber"])
    for articlecount in publication["articleCounts"]:
        publications[publication["publicationNumber"]][
            articlecount["year"]] += int(articlecount["articleCount"])
        # actual_year = max(actual_year, int(articlecount["year"]))

for i in range(n - 1):
    cit = json.loads(input())
    for c in cit["paperCitations"]["ieee"]:
        pnum = c["publicationNumber"]
        pyear = c["year"]
        if pnum in publications:
            if pyear in publications[pnum]:
                citations[pnum][pyear] += 1

pubnumbs.sort(key=getif, reverse=False)

for pn in pubnumbs:
    print(f"{names[pn]}: {IF(actual_year, pn):.2f}")
