/*define(['threejs'], function($) {

    function initTrees(scene) {
        var xPlace = -90;
        for (var i = 0; i < 31; i++) {
            if (i % 3 == 0) {
                createTree(xPlace-3, 1, -5.6, scene);
                createTree(xPlace-3, 1, 1.9, scene);
            }
            //Every three x places you want another house
            xPlace += 6;
        }
    }



    return {
        initTrees: function(scene) {
            initTrees(scene);
        }
    }
});*/

// createTree function creates a tree at the given x, y, z coordinates
function createTree(xValue, yValue, zValue, scene) {
    var cylinderGeometry = new THREE.CylinderGeometry(0.8,0.8,4);
    var cylinderMaterial = new THREE.MeshLambertMaterial({color: 0x5F1700});
    var cylinder = new THREE.Mesh(cylinderGeometry,cylinderMaterial);
    cylinder.position.x = xValue;
    cylinder.position.y = yValue;
    cylinder.position.z = zValue;
    scene.add(cylinder);

    var geometrySphere = new THREE.SphereGeometry(1.4, 16, 24);
    var materialLambert = new THREE.MeshLambertMaterial({color: 0x458B00});
    var sphere = new THREE.Mesh(geometrySphere, materialLambert);
    sphere.position.x = xValue;
    sphere.position.y = yValue + 3.0;
    sphere.position.z = zValue;
    scene.add(sphere);
}