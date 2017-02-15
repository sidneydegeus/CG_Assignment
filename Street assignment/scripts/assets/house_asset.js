
//This is the function that creates a house for the front side and back side (using a if statement rotated)
function createHouse(xValue, yValue, zValue, rotated, scene){
    //This will be the cube. A cyclinder will be placed on top of this so it looks like a house
    var cubeGeometry = new THREE.BoxGeometry(4,4,4);
    var cubeMaterial = new THREE.MeshBasicMaterial({
        map: THREE.ImageUtils.loadTexture('img/wall.jpg')
    });
    var cube = new THREE.Mesh(cubeGeometry, cubeMaterial);
    cube.position.x = xValue;
    cube.position.y = yValue;
    cube.position.z = zValue;

    //This will be the door

    var doorGeometry = new THREE.BoxGeometry(0.6,1.8,0.1);
    var doorMaterial = new THREE.MeshBasicMaterial({
        map: THREE.ImageUtils.loadTexture('img/door.png')
    });
    var door = new THREE.Mesh(doorGeometry, doorMaterial);
    if(rotated == true) {
        door.position.x = xValue;
        door.position.y = yValue - 1.2;
        door.position.z = zValue - 2.1;
    }
    else {
        door.position.x = xValue;
        door.position.y = yValue - 1.2;
        door.position.z = zValue + 2;
    }

    //There are three types of windows. To make the house look a little bit better.
    //This is the first window
    var windowGeometry = new THREE.BoxGeometry(1,1,0.1);
    var windowMaterial = new THREE.MeshBasicMaterial({
        map: THREE.ImageUtils.loadTexture('img/window.jpg')
    });
    var window = new THREE.Mesh(windowGeometry, windowMaterial);
    if(rotated == true) {
        window.position.x = xValue + 1.2;
        window.position.y = yValue - 0.8;
        window.position.z = zValue - 2.1;
    }
    else {
        window.position.x = xValue - 1.2;
        window.position.y = yValue - 0.8;
        window.position.z = zValue + 2;
    }

    //This is the second window
    var window2Geometry = new THREE.BoxGeometry(1,1,0.1);
    var window2Material = new THREE.MeshBasicMaterial({
        map: THREE.ImageUtils.loadTexture('img/window.jpg')
    });
    var window2 = new THREE.Mesh(window2Geometry, window2Material);
    if(rotated == true) {
        window2.position.x = xValue - 1.2;
        window2.position.y = yValue + 1.1;
        window2.position.z = zValue - 2.1;
    }
    else {
        window2.position.x = xValue - 1.2;
        window2.position.y = yValue + 1.1;
        window2.position.z = zValue + 2;
    }

    //This is the third window
    var window3Geometry = new THREE.BoxGeometry(1,1,0.1);
    var window3Material = new THREE.MeshBasicMaterial({
        map: THREE.ImageUtils.loadTexture('img/window.jpg')
    });
    var window3 = new THREE.Mesh(window3Geometry, window3Material);
    if(rotated == true) {
        window3.position.x = xValue + 1.2;
        window3.position.y = yValue + 1.1;
        window3.position.z = zValue - 2.1;
    }
    else {
        window3.position.x = xValue + 1.2;
        window3.position.y = yValue + 1.1;
        window3.position.z = zValue + 2;
    }

    //This is the cyclinder that is on top of the house
    var cylinderGeometry = new THREE.CylinderGeometry(0.2,3.0,1.0);
    var cylinderMaterial = new THREE.MeshBasicMaterial({
        map: THREE.ImageUtils.loadTexture('img/roof.jpg')
    });
    var cylinder = new THREE.Mesh(cylinderGeometry,cylinderMaterial);
    cylinder.position.x = xValue;
    cylinder.position.y = yValue + 2.5;
    cylinder.position.z = zValue + 0.1;

    scene.add(cube);
    scene.add(door);
    scene.add(window);
    scene.add(window2);
    scene.add(window3);
    scene.add(cylinder);
}