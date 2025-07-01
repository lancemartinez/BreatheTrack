import folium
import numpy as np
from scipy.interpolate import griddata

loudoun_center = [39.0834, -77.6497]
m = folium.Map(location=loudoun_center, zoom_start=11)

def generate_random_blotches(num_blotches=20):
    blotches = []
    for _ in range(num_blotches):
        lat = np.random.uniform(38.8, 39.2)
        lon = np.random.uniform(-77.9, -77.4)
        radius = np.random.uniform(500, 2000)
        aqi_value = np.random.uniform(0, 100)
        blotches.append({
            "location": [lat, lon],
            "radius": radius,
            "aqi": aqi_value
        })
    return blotches

blotches = generate_random_blotches(num_blotches=30)
points = np.array([blotch["location"] for blotch in blotches])
values = np.array([blotch["aqi"] for blotch in blotches])

grid_lat, grid_lon = np.meshgrid(
    np.linspace(38.8, 39.2, 100),
    np.linspace(-77.9, -77.4, 100)
)
grid_points = np.vstack([grid_lat.ravel(), grid_lon.ravel()]).T
grid_aqi = griddata(points, values, grid_points, method="cubic")
grid_aqi = grid_aqi.reshape(grid_lat.shape)

aqi_min, aqi_max = grid_aqi.min(), grid_aqi.max()
grid_aqi_normalized = (grid_aqi - aqi_min) / (aqi_max - aqi_min)

for i in range(grid_lat.shape[0] - 1):
    for j in range(grid_lat.shape[1] - 1):
        lat1, lon1 = grid_lat[i, j], grid_lon[i, j]
        lat2, lon2 = grid_lat[i + 1, j + 1], grid_lon[i + 1, j + 1]
        aqi_value = grid_aqi_normalized[i, j]
        if np.isnan(aqi_value):
            continue
        green_shade = int(255 * (1 - aqi_value))
        fill_color = f"#00{green_shade:02x}00"
        folium.Rectangle(
            bounds=[[lat1, lon1], [lat2, lon2]],
            color=fill_color,
            fill=True,
            fill_color=fill_color,
            fill_opacity=0.5,
            weight=0
        ).add_to(m)

m.save("loudoun_aqi_heatmap.html")
