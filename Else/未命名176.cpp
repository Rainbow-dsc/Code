
<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	    <link rel="stylesheet" href="/Public/bootstrap-3.3.7-dist/css/bootstrap-theme.css" />
	    <link rel="stylesheet" href="/Public/bootstrap-3.3.7-dist/css/bootstrap.css" />
		<link rel="shortcut icon" href="/Public/img/onecode.png" type="image/x-icon" />
		
	<style type="text/css">
		.mes-row-item{
			color: #0066FF;
		}
		p{
			font-size: 18px;
			font-weight: 600;
		}
		pre{
			margin-left: 15px;
		}
		.mysapn{
			white-space: pre-wrap;       
			white-space: -moz-pre-wrap;  
			white-space: -pre-wrap;      
			white-space: -o-pre-wrap;    
			word-wrap: break-word;
			font-family: "Microsoft YaHei";
			font-size: 15px;
			line-height: 150%;
			background-color: #FFFFFF;
			border-width: 0;
		}
		.pre2{
			white-space: pre-wrap;       
			white-space: -moz-pre-wrap;  
			white-space: -pre-wrap;      
			white-space: -o-pre-wrap;    
			word-wrap: break-word;
			font-family: "Microsoft YaHei";
			font-size: 15px;
			line-height: 150%;
			background-color: #FFFFFF;
		}
	</style>
	<link rel="stylesheet" href="/Public/codemirror/lib/codemirror.css">
	<link rel="stylesheet" href="/Public/codemirror/theme/eclipse.css">

		<script language="javascript" src="/Public/bootstrap-3.3.7-dist/js/jquery-1.12.2.min.js"></script>
		<script language="javascript" src="/Public/bootstrap-3.3.7-dist/js/bootstrap.js"></script>
		
		<title>
			
				一码学程
			
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
																					 <li class="dropdown">
												 <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false" style="color: #2c7e92;"> qwertyuiop												 <span class="caret"></span></a>
												 <ul class="dropdown-menu">
												  
													<li><a href="/index.php/User/showUserMessage/id/652"><span class="glyphicon glyphicon-user" aria-hidden="true"></span>&nbsp;&nbsp;我的信息</a></li>
													<li><a href="/index.php/User/showModifyUserMessage/id/652"><span class="glyphicon glyphicon-user" aria-hidden="true"></span>&nbsp;&nbsp;修改信息</a></li>
													<li><a href="/index.php/User/showModifyPassword/id/652"><span class="glyphicon glyphicon-user" aria-hidden="true"></span>&nbsp;&nbsp;修改密码</a></li>
													<li><a href="/index.php/User/showAllSubmitRecordPage/id/652"><span class="glyphicon glyphicon-user" aria-hidden="true"></span>&nbsp;&nbsp;提交记录</a></li>
																																							<li><a href="/index.php/User/logout"><span class="glyphicon glyphicon-off" aria-hidden="true"></span>&nbsp;&nbsp;退出登录</a></li>
													<li role="separator" class="divider"></li>
											  </ul>
												  
											</li>										
									  </ul>
									</div><!-- /.navbar-collapse -->
								  </div><!-- /.container-fluid -->
								</nav>
							</div>
						</div>
		
			<div class="row">
				<div class="col-md-12">
					<div class="btn-group" role="group" aria-label="...">
					  <a href="/index.php/Train/showProblemList" class="btn btn-primary">题目</a>
					  <a href="/index.php/Train/showRankPage" class="btn btn-info">排行</a>
					  <a href="/index.php/Train/showTaskJudge" class="btn btn-info">评测</a>
					  <a href="/index.php/Train/showBBS" class="btn btn-success">讨论</a>
					</div>
				</div>
				<hr />
				<div class="col-md-12">
					<div class="row">
						
	<div class="row">
		<div class="col-md-12 text-center">
			  <h2> G <span>:</span> 统计字符 </h2>
		</div>
	</div>
	<div class="row text-center" style="margin-bottom: 30px;">
		<div class="col-md-12">
			<span class="mes-row-item">时间限制: 1000 MS</span>
			<span class="mes-row-item">内存限制: 131072 KB</span>
			<span class="mes-row-item">提交总数: 223</span>
			<span class="mes-row-item">AC总数: 73</span>
		</div>
	</div>
	<div class="row text-center">
		<div class="col-md-12">
			
		</div>
	</div>
	<div class="row">
		<div class="col-md-12">
			<div class="panel panel-success">
			  <div class="panel-heading">问题描述</div>
			  <div class="panel-body">
			  	<span class="mysapn">输入一串字符（仅包含英文字母，空格和数字），分别统计其中英文字母，空格，数字的个数。</span>
			  </div>
			</div>
		</div>
	</div>
	<div class="row">
		<div class="col-md-12">
			<div class="panel panel-info">
			  <div class="panel-heading">输入格式</div>
			  <div class="panel-body">
			  	<span class="mysapn">一串字符（仅包含英文字母（letters），空格（space）和数字（digit））（1&lt;=长度&lt;=60）。</span>
			  </div>
			</div>
		</div>
	</div>
	<div class="row">
		<div class="col-md-12">
			<div class="panel panel-info">
			  <div class="panel-heading">输出格式</div>
			  <div class="panel-body">
			  	<span class="mysapn">分别输出字母，空格和数字的数量,数量之间以一个空格隔开。</span>
			  </div>
			</div>
		</div>
	</div>
	<div class="row">
		<div class="col-md-12">
			<div class="panel panel-warning">
			  <div class="panel-heading">样例输入</div>
			  <div class="panel-body">
			  	<span class="mysapn">q1 2w</span>
			  </div>
			</div>
		</div>
	</div>
	<div class="row">
		<div class="col-md-12">
			<div class="panel panel-warning">
			  <div class="panel-heading">样例输出</div>
			  <div class="panel-body">
			  	<span class="mysapn">letters:2 space:1 digit:2</span>
			  </div>
			</div>
		</div>
	</div>
	<div class="row">
		<div class="col-md-12">
			<div class="panel panel-danger">
			  <div class="panel-heading">作者</div>
			  <div class="panel-body">
			  	<span class="mysapn">lq</span>
			  </div>
			</div>
		</div>
	</div>
	<div class="row">
		<div class="col-md-12">
			<div class="panel panel-danger">
			  <div class="panel-heading">来源</div>
			  <div class="panel-body">
			  	<span class="mysapn">OneCode</span>
			  </div>
			</div>
		</div>
	</div>
	<form class="form-inline" action="/index.php/Train/onlineJudge" method="post">
		<input type="hidden" name="problemID"  value="206" />
		<input type="hidden" name="level_msg_id" id="level_msg_id" value="92" />
		<div class="form-group" style="margin-top: 20px;">
		   <label style="font-size: 18px;">语言</label>
		   <select name="language" class="form-control">
		   			   			<option value="C++">C++</option>		   			<option value="C">C</option>		   			<option value="PASCAL">PASCAL</option>			</select>
		</div>
		<div class="row" style="margin-top: 20px;">
			<div class="col-md-12">
				<div class="panel panel-default">
				  <div class="panel-heading">你的源代码</div>
				  <div class="panel-body">
				    <textarea id="editor" name="editor"></textarea>
				  </div>
				</div>
			</div>
		</div>
	
		<div class="row" style="margin-top: 15px;">
			<div class="col-md-12 text-center">
				<div class="btn-group" role="group" aria-label="...">
					<div class="row">
						<div class="col-lg-3">
							
								<input class="btn  btn-primary" type="submit" value="提交代码" >
							 
						</div>
					</div>
				</div>
			</div>
		</div>
	</form>
	<script src="/Public/codemirror/lib/codemirror.js"></script>
	<script src="/Public/codemirror/mode/clike/clike.js"></script>
	<script type="text/javascript">
		var myTextarea = document.getElementById('editor');
		var CodeMirrorEditor = CodeMirror.fromTextArea(myTextarea, {
		    mode: "text/x-c++src",
		    matchBrackets: true,
		    indentUnit:4,
		    theme:'eclipse',
			lineNumbers: true
		});	
	</script>
	<!--<div class="col-md-12" style="padding-top: 40px;">
		<div class="upper">
			<h3 class="text-center"> 统计字符 </h3>
			<div class="upper-message text-center" style="color: #C12E2A;">
				<div class="mes-row">
					<span class="mes-row-item">Time Limit: 1000 MS</span>
					<span class="mes-row-item">Memory Limit: 131072 K </span>
				</div>
				<div class="mes-row">
					<span class="mes-row-item">Total Submission(s): 223</span>
					<span class="mes-row-item">Accepted Submission(s): 73</span>
				</div>
			</div>
		</div>
		<div class="middle">
			<div class="list">
				<h5>问题描述</h5>
				<div class="list-message"><pre>输入一串字符（仅包含英文字母，空格和数字），分别统计其中英文字母，空格，数字的个数。</pre></div>
			</div>
			<div class="list">
				<h5>输入格式</h5>
				<div class="list-message"><pre>一串字符（仅包含英文字母（letters），空格（space）和数字（digit））（1&lt;=长度&lt;=60）。</pre></div>
			</div>
			<div class="list">
				<h5>输出格式</h5>
				<div class="list-message"><pre>分别输出字母，空格和数字的数量,数量之间以一个空格隔开。</pre></div>
			</div>
			<div class="list">
				<h5>样例输入 </h5>
				<div class="list-message">
					<pre>q1 2w</pre>
				</div>
			</div>
			<div class="list">
				<h5>样例输出 </h5>
				<div class="list-message">
					<pre>letters:2 space:1 digit:2</pre>
				</div>
			</div>
			<div class="list">
				<h5>作者 </h5>
				<pre> lq</pre>
			</div>
			<div class="list">
				<h5>来源 </h5>
				<pre> OneCode</pre>
			</div>
			
			<div class="submit">
			<a href="/index.php/Train/showSubmit/id/206/level_msg_id/92/title/统计字符">提交代码</a>
			</div>
		</div>
	</div>-->

					</div>
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
