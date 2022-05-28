import json
import sys

with open( sys.argv[1] ) as f:
    data = json.load(f)

print( 'No errors!' )

