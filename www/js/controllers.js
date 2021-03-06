angular.module('starter.controllers', [])

.controller('DashCtrl', function($scope) {
  $scope.user = {velocity:'500'};
	$scope.cor = {valor: '#'};
	$("#custom").spectrum({
   		color: "#f00",
   		flat: true,
   		change: function(color){ 
   		},
      move : function(color){
        $('#colorv').text(color.toHexString());
        str = color.toHexString();

        r = parseInt(str[1]+str[2],16);
        r = r.toString().length < 3 ? '0' + r : r;
        g = parseInt(str[3] + str[4],16);
        g = g.toString().length < 3 ? '0' + g : g;
        b = parseInt(str[5] + str[6],16);
        b = b.toString().length < 3 ? '0' + b : b;
        str = r + ' ' + g + ' ' + b;
        $('#colors').text(r + ' ' + g + ' ' + b);
        console.log(str);
        $scope.enviarAlgo(str);
      }
	});

  $scope.enviarVelocidade = function(){
    bluetoothSerial.write('V' + String($scope.user.velocity),function(){     
    },function(){
      alert('erro');
    });
  }

  $scope.ascendeTodos = function(){
    bluetoothSerial.write('all',function(){     
    },function(){
      alert('erro');
    });
  }

  $scope.iluminarVermelho = function(){
    bluetoothSerial.write('0R',function(){     
    },function(){
      alert('erro');
    });
  }
  $scope.iluminarVerde = function(){
    bluetoothSerial.write('0G',function(){     
    },function(){
      alert('erro');
    });
  }
  $scope.iluminarAzul = function(){
    bluetoothSerial.write('0B',function(){     
    },function(){
      alert('erro');
    });
  }

	$scope.enviarAlgo = function(cor){
		bluetoothSerial.write(cor,function(){			
		},function(){
			alert('erro');
		});
	}

	$scope.validar = function(cor){
		console.log(cor);
	}
})

.controller('FriendsCtrl', function($scope, Friends) {
  $scope.friends = Friends.all();
})

.controller('FriendDetailCtrl', function($scope, $stateParams, Friends) {
  $scope.friend = Friends.get($stateParams.friendId);
})

.controller('AccountCtrl', function($scope) {
});
