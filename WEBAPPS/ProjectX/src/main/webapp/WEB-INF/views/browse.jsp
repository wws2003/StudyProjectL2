<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head>
<style type="text/css">
table,td,th {
	border-collapse: collapse;
	border: 0px solid;
}

td,th {
	text-align: center;
	padding-left: 20px;
	margin-left: 0px;
	margin-right: 0px;
	padding-right: 20px;
}

.page_line {
	display: inline-block;
	margin-top: 20px;
	margin-bottom: 20px;
}
</style>
</head>
<body>
	<h2>Simplest CI !</h2>
	<c:choose>
		<c:when test="${!isFileObject}">
			<div style="padding-left: 30px">
				Directory content
				<table>
					<tr>
						<th>Name</th>
						<th>Last modified</th>
					</tr>
					<c:forEach items="${childBrowsingObjects}" var="element">
						<tr>
							<c:choose>
								<c:when test="${element.objectType == 0}">
									<td style="text-align: left;">---------------<a href="<c:url value="/open/${element.id}"></c:url>">${element.name}</a></td>
								</c:when>
								<c:otherwise>
									<td style="text-align: left;"><a href="<c:url value="/browse/${element.id}"></c:url>">${element.name}</a>/</td>
								</c:otherwise>
							</c:choose>
							<td>${element.modifiedTime}</td>
						</tr>
					</c:forEach>
				</table>
			</div>
			<div style="padding-left: 30px; margin-top: 40px">
				<a href='<c:url value="/home"></c:url>'>To home page</a>
			</div>
		</c:when>
		<c:otherwise>
			File object can't be browsed. Open instead
		</c:otherwise>
	</c:choose>
</body>
</html>
