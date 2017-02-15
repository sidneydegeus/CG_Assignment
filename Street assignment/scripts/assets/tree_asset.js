

// createTree function creates a tree at the given x, y, z coordinates
function createTree(xValue, yValue, zValue, scene) {

    var loader = new THREE.ObjectLoader();
    loader.load("models/tree-toon.json",function ( obj ) {
         obj.position.x = xValue;
         obj.position.y = yValue - 0.4;
         obj.position.z = zValue;
        scene.add( obj );
    });
}