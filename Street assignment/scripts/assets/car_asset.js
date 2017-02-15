
// a car object that contains specific variables to what a car contains and such
function car(carBody, carRoof, wheels, carLights, direction, isDriving, spotlights) {
    this.carBody = carBody;
    this.carRoof = carRoof
    this.wheels = wheels
    this.carLights = carLights;
    this.direction = direction;
    this.isDriving = isDriving;
    this.isLightsOn = false;
    this.carSpotlights = spotlights
}

// createCar function creates a car at the given x, y, z coordinates and faces/drives
// a specific direction and whether it is driving as well
function createCar(xValue, yValue, zValue, direction, isDriving, scene) {
    var geometryCarBody = new THREE.BoxGeometry(1.5, 0.7, 1);
    // geometry and mesh for the body of the car
    for ( var i = 0; i < geometryCarBody.faces.length; i ++ ) {
        var face = geometryCarBody.faces[ i ];
        face.color.setHex( Math.random() * 0xffffff );
    }
    var material = new THREE.MeshLambertMaterial({vertexColors: THREE.FaceColors});
    var carBody = new THREE.Mesh(geometryCarBody, material);
    carBody.position.x = xValue;
    carBody.position.y = yValue - 0.5;
    carBody.position.z = zValue;

    // geometry and mesh for the roof of the car
    var geometryCarRoof = new THREE.BoxGeometry(0.7, 0.5, 1);
    // geometry and mesh for the body of the car
    for ( var i = 0; i < geometryCarRoof.faces.length; i ++ ) {
        var face = geometryCarRoof.faces[ i ];
        face.color.setHex( Math.random() * 0xffffff );
    }
    var material = new THREE.MeshLambertMaterial({vertexColors: THREE.FaceColors});
    var carRoof = new THREE.Mesh(geometryCarRoof, material);
    carRoof.position.x = xValue;
    carRoof.position.y = yValue + 0.1;
    carRoof.position.z = zValue;

    var carLightGeometry = new THREE.BoxGeometry(0.025, 0.3, 0.2);
    var carLightMaterial = new THREE.MeshLambertMaterial({color: 0x8c8c8c});
    var carLights = [];
    var spotlights = [];
    // a car as 2 front lights, so we'll add them to the scene and to an array
    for (var i = 0; i < 2; i++) {
        var carLight = new THREE.Mesh(carLightGeometry, carLightMaterial);
        var carLightXPos = direction ? xValue + .75 : xValue - .75;
        var carLightYPos  = yValue - 0.35;
        var carLightZPos = i == 0 ? zValue + 0.25 : zValue - 0.25;
        carLight.position.x = carLightXPos;
        carLight.position.y = carLightYPos;
        carLight.position.z = carLightZPos;
        carLight.rotation.x = Math.PI / 2;
        carLights[i] = carLight;

        // each frontlight has a spotlight as well
        var spotlight = new THREE.SpotLight(0xffffff);
        spotlight.position.set(carLightXPos,carLightYPos,carLightZPos);
        spotlight.lookAt(
            direction ? carLightXPos + 2 : carLightXPos - 2,
            carLightYPos - 0.2,
            carLightZPos
        );
        spotlights[i] = spotlight
        scene.add(carLight);
    }

    // geometry and mesh for the wheels of the car
    var wheelGeometry = new THREE.CylinderGeometry(0.2, 0.2, 0.2);
    var wheelMaterial = new THREE.MeshLambertMaterial({color: 0x5F1700});
    var wheels = [];
    // a car has 4 wheels, so we'll add them to the scene and to an array
    for (var i = 0; i < 4; i++) {
        var wheel = new THREE.Mesh(wheelGeometry, wheelMaterial);
        if (i == 0 || i == 2) {
            wheel.position.z = zValue + 0.45;
        } else {
            wheel.position.z = zValue - 0.45;
        }
        if (i > 1) {
            wheel.position.x = xValue + 0.45;
        } else {
            wheel.position.x = xValue - 0.45;
        }
        wheel.position.y = yValue - 0.82;
        wheel.rotation.x = Math.PI / 2;
        wheels[i] = wheel;
        scene.add(wheel);
    }

    scene.add(carBody);
    scene.add(carRoof);

    // return a new car object with the car body, car roof, car wheels etc...
    return new car(carBody, carRoof, wheels, carLights, direction, isDriving, spotlights);
}