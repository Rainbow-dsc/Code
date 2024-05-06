
<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	    <link rel="stylesheet" href="/Public/bootstrap-3.3.7-dist/css/bootstrap-theme.css" />
	    <link rel="stylesheet" href="/Public/bootstrap-3.3.7-dist/css/bootstrap.css" />
		<link rel="shortcut icon" href="/Public/img/onecode.png" type="image/x-icon" />
		
		<script language="javascript" src="/Public/bootstrap-3.3.7-dist/js/jquery-1.12.2.min.js"></script>
		<script language="javascript" src="/Public/bootstrap-3.3.7-dist/js/bootstrap.js"></script>
		
		<title>
		</title>
	</head>	
	<body>
		
			<div class="container-fluid">
				<div class="row">
					<div class="col-md-10 col-md-offset-1">
						<div class="row">
							<div class="col-md-12">
								<nav class="navbar navbar-default">
								  <div class="container-fluid">
									<!-- Brand and toggle get grouped for better mobile display -->
									<div class="navbar-header">

									  	<img src="/Public/img/tm.png" alt="" />

									</div>
									<div class="collapse navbar-collapse navbar-right" id="bs-example-navbar-collapse-1">
									  <ul class="nav navbar-nav" style="font-size: 20px;">
										<li><a href="/index.php/Index/index" style="color: #2c7e92;">首页</a></li>
										
										<li><a href="/index.php/Problem/showProblemList" style="color: #2c7e92;">题库</a></li>
										<li><a href="/index.php/Judge/showRealTimeEvaluation" style="color: #2c7e92;">状态</a></li>
										<li><a href="/index.php/Ladder/showContestListPage" style="color: #2c7e92;">天梯</a></li>
									  	<li><a href="/index.php/Train/index" style="color: #2c7e92;">课程</a></li>
									  	<li><a href="/index.php/Exam/index" style="color: #2c7e92;">比赛</a></li>
									  	<li><a href="/index.php/User/showAllUserRank" style="color: #2c7e92;">排行榜</a></li>
									  	<!--<li><a href="/index.php/Exam/index">比赛</a></li>-->
									  	<!--<li><a href="/index.php/Forum/showForum">留言区</a></li>-->
									  </ul>
									  
									  <ul class="nav navbar-nav navbar-right">
										<li><a href="/index.php/User/showLogin" style="color: #2c7e92;">登录</a></li>
											<!--<li><a href="/index.php/User/showRegister">注册</a></li>-->
																					
									  </ul>
									</div><!-- /.navbar-collapse -->
								  </div><!-- /.container-fluid -->
								</nav>
							</div>
						</div>	
		
		
	<div class="row" style="margin-top: 50px;">
		<div class="col-md-12">
			<h2 class="text-center" style="color: #2c7e92;">登录</h2>
		</div>
	</div>
	<div class="row" style="margin-top: 50px;margin-bottom: 125px;">
		<div class="col-md-4 col-md-offset-4">
			<form class="form-horizontal form" action="/index.php/User/login" method="post">
			  <div class="form-group">
			    <label for="inputEmail3" class="col-sm-2 control-label">
			    	<span class="glyphicon glyphicon-user"  style="color:#2c7e92;font-size:21px;"></span>
			    </label>
			    <div class="col-sm-8">
			      <input type="text" class="form-control" id="inputEmail3" name="username" required>
			    </div>
			  </div>
			  <div class="form-group">
			    <label for="inputPassword3" class="col-sm-2 control-label">
			    	<span class="glyphicon glyphicon-lock" style="color:#2c7e92;font-size:21px;"></span>
			    </label>
			    <div class="col-sm-8">
			      <input type="password" class="form-control" id="inputPassword3" name="password" required>
			    </div>
			  </div>
			  <div class="form-group">
			    <div class="col-sm-offset-2 col-sm-8">
			      <button type="submit" class="btn btn-default btn-block" style="background-color: #0aa4c8;color: #FFFFFF;font-size: 18px;">登 录</button>
			    </div>
			  </div>
			  <div class="form-group">
			    <div class="col-sm-offset-2 col-sm-8 text-right">
			      <div class="checkbox">
			        <a href="/index.php/User/showGetMail" style="color: #0000FF;">忘记密码</a>
			      </div>
			    </div>
			  </div>
			  
			</form>
		</div>
	</div>

		
						<div class="row">
				<div class="col-md-12">
					<div class="footer">
						<hr>
						<div class="row footer-bottom">
				          <ul class="list-inline text-center">
				            <li>ONECODE在线评测系统</li>
				            <li>|</li>
							<li>Copyright &copy; 2017-2018  author:ONECODE</li>
				          </ul>
				        </div>
					</div>
					<script>
						
						/*导航*/
						(function(){
							if(window.sessionStorage){
				
								var nav = $('.navbar-nav');
								nav.find('li')
									.on('click',function(){
										sessionStorage.activeIndex = $(this).index();
										$(this).addClass('active')
											.siblings()
											.removeClass('active');
										
									})
									.eq(sessionStorage.activeIndex)
									.addClass('active')
									.siblings()
									.removeClass('active');
							}
						})();
					</script>
				</div>
			</div>
		</div>
	</div>
</div>
		
		
	</body>
</html>
