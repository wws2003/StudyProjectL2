<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head>
<c:if test="${empty builtInfoPage}">
<meta http-equiv="refresh" content="5;url=<c:url value="/buildlist"></c:url>">
</c:if>
<style type="text/css">
table,td,th {
	border-collapse: collapse;
	border: 1px solid black;
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
		<c:when test="${serviceAvailable}">
			Service available
			<div>
				<b>Building list</b>
				<table>
					<tr>
						<th>Id</th>
						<th>Status</th>
						<th>Begin time</th>
						<th>Log file path</th>
					</tr>
					<c:forEach items="${buildingList}" var="element">
						<tr>
							<td>${element.id}</td>
							<td>Building</td>
							<td>${element.beginTimeStamp}</td>
							<td>${element.logFilePath}</td>
						</tr>
					</c:forEach>
				</table>
			</div>
			<div>
				<b>Waiting list</b>
				<table>
					<tr>
						<th>Id</th>
						<th>Status</th>
					</tr>
					<c:forEach items="${waitingList}" var="element">
						<tr>
							<td>${element.id}</td>
							<td>${element.status == 0 ? "Waiting" : "Cancelled"}</td>
							<td><a href='<c:url value="/cancel/${element.id}"></c:url>'>Cancel</a></td>
						</tr>
					</c:forEach>
				</table>
			</div>
			<c:if test="${not empty builtInfoPage}">
				<div>
					<b>Built list</b>
					<table>
						<tr>
							<th>Id</th>
							<th>Status</th>
							<th>Begin time</th>
							<th>End time</th>
							<th>Log file path</th>
							<th>Log detail</th>
						</tr>
						<c:forEach items="${builtInfoPage.builtInfoList}" var="element">
							<tr>
								<td>${element.id}</td>
								<td>${element.status == 0 ? "OK" : (element.status == 2 && empty element.beginTimeStamp ? "Cancelled by user" : "NG")}</td>
								<td>${element.beginTimeStamp}</td>
								<td>${element.endTimeStamp}</td>
								<td>${element.logFilePath}</td>
								<c:url value="/log/${element.id}" var="logUrl"></c:url>
								<td><c:if test="${not empty element.beginTimeStamp}"><a href='${logUrl}'>Detail</a></c:if></td>
							</tr>
						</c:forEach>
					</table>
				</div>
				<div class="page_line">
					<a href='<c:url value="/buildlist/?page=1"></c:url>'>First </a>
					&nbsp;
					<c:if test="${builtInfoPage.page > 1}"><a href='<c:url value="/buildlist/?page=${builtInfoPage.page - 1}"></c:url>'>Prev </a></c:if>
					&nbsp;
					<c:out value="(${builtInfoPage.firstId} - ${builtInfoPage.lastId}) / ${builtInfoPage.maxId}"></c:out>
					&nbsp;
					<c:if test="${builtInfoPage.lastId < builtInfoPage.maxId}"><a href='<c:url value="/buildlist/?page=${builtInfoPage.page + 1}"></c:url>'>Next </a></c:if>
					&nbsp;
					<a href='<c:url value="/buildlist/?page=${builtInfoPage.lastPage}"></c:url>'> Last</a>
				</div>
			</c:if>
			<div>
				<a href='<c:url value="/home"></c:url>'>To home page</a>
			</div>
		</c:when>
		<c:otherwise>
			Service not available
		</c:otherwise>
	</c:choose>
</body>
</html>
