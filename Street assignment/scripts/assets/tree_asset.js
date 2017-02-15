

// createTree function creates a tree at the given x, y, z coordinates
function createTree(xValue, yValue, zValue, scene) {
    /*
    var cylinderGeometry = new THREE.CylinderGeometry(0.8,0.8,4);
    var cylinderMaterial = new THREE.MeshLambertMaterial({color: 0x5F1700});
    var cylinder = new THREE.Mesh(cylinderGeometry,cylinderMaterial);
    cylinder.position.x = xValue;
    cylinder.position.y = yValue + 1.0;
    cylinder.position.z = zValue;
    scene.add(cylinder);

    var geometrySphere = new THREE.SphereGeometry(1.4, 16, 24);
    var materialLambert = new THREE.MeshLambertMaterial({color: 0x458B00});
    var sphere = new THREE.Mesh(geometrySphere, materialLambert);
    sphere.position.x = xValue;
    sphere.position.y = yValue + 4.0;
    sphere.position.z = zValue;
    scene.add(sphere); */

    var loader = new THREE.ObjectLoader();
    loader.load("models/tree-toon.json",function ( obj ) {
         obj.position.x = xValue;
         obj.position.y = yValue - 0.4;
         obj.position.z = zValue;
        scene.add( obj );
    });
}