from flask import Flask, render_template, jsonify

app = Flask(__name__)

bolen = list(open("uploads/bolen.txt", "r").read().splitlines())
leesburg = list(open("uploads/leesburgoutlets.txt", "r").read().splitlines())
idalee = list(open("uploads/idalee.txt", "r").read().splitlines())

bolelabels = list(range(len(bolen)))
leeslabels = list(range(len(leesburg)))
idalabels = list(range(len(idalee)))

@app.route('/')
def homepage():
    return render_template(
        'index.html',
        data_bolen=bolen[:10],  
        labels_bolen=bolelabels[:10],
        data_leesburg=leesburg[:10],
        labels_leesburg=leeslabels[:10],
        data_idalee=idalee[:10], 
        labels_idalee=idalabels[:10] 
    )

@app.route('/get_new_data')
def get_new_data():
    if len(bolen) > 0 and len(leesburg) > 0 and len(idalee) > 0:
        new_bolen_data = bolen.pop(0)
        new_leesburg_data = leesburg.pop(0)
        new_idalee_data = idalee.pop(0)

        new_bolen_label = len(bolelabels)
        new_leesburg_label = len(leeslabels)
        new_idalee_label = len(idalabels)

        bolelabels.append(new_bolen_label)
        leeslabels.append(new_leesburg_label)
        idalabels.append(new_idalee_label)

        return jsonify({
            'new_bolen_data': new_bolen_data,
            'new_bolen_label': new_bolen_label,
            'new_leesburg_data': new_leesburg_data,
            'new_leesburg_label': new_leesburg_label,
            'new_idalee_data': new_idalee_data,
            'new_idalee_label': new_idalee_label
        })
    else:
        return jsonify({
            'new_bolen_data': None,
            'new_bolen_label': None,
            'new_leesburg_data': None,
            'new_leesburg_label': None,
            'new_idalee_data': None,
            'new_idalee_label': None
        })
    
@app.route('/datacollection')
def folmap():
    return render_template("loudoun_aqi_map.html")

@app.route('/inferences')
def inferencemap():
    return render_template("loudoun_aqi_heatmap.html")

if __name__ == '__main__':
    app.run(debug=True)