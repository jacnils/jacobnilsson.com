const SHEET_ID = "11lMWhl94H1di4_rKt5wCE8RUhMz_U3KIP0Pg0QVubZw";
const SHEET_URL = "https://docs.google.com/spreadsheets/d/" + SHEET_ID + "/gviz/tq?tqx=out:json";
const GDDL_MAX_TIER = 39;

const headers = [
    "Level","Level ID","Completed on","Experience/Enjoyment (GDDL)",
    "Decoration Score","Gameplay Score","Music Score","Score",
    "Proof (GDDL)","Rating (GDDL)","NLW Opinion","Worst Fail",
    "Attempts (from 0%)","Attempts (practice)","Playtime (from 0%)",
    "Playtime (practice)","Note"
];

const sortFields = {
    "Enjoyment": "Experience/Enjoyment (GDDL)",
    "Decoration": "Decoration Score",
    "Gameplay": "Gameplay Score",
    "Music": "Music Score",
    "Overall": "Score",
    "Tier": "Rating (GDDL)"
};

let entries = [];
let currentSort = null;
let ascending = false;
let tierFilter = null;

async function loadSheet() {
    const res = await fetch(SHEET_URL);
    const text = await res.text();
    const json = JSON.parse(text.substr(47).slice(0, -2));
    return json.table.rows;
}

function rowToObject(row) {
    const obj = {};
    headers.forEach((h, i) => {
        obj[h] = row.c[i]?.v || "";
    });
    return obj;
}

function createControls() {

    const container = document.getElementById("content");

    const controls = document.createElement("div");
    controls.id = "controls";

    Object.entries(sortFields).forEach(([label, field]) => {
        const btn = document.createElement("button");
        btn.textContent = label;

        btn.onclick = () => {
            if (currentSort === field) {
                ascending = !ascending;
            } else {
                currentSort = field;
                ascending = false;
            }
            update();
        };

        controls.appendChild(btn);
    });

    const filter = document.createElement("select");

    const allOption = document.createElement("option");
    allOption.value = "";
    allOption.textContent = "All Tiers";
    filter.appendChild(allOption);

    for (let i = 1; i <= GDDL_MAX_TIER; i++) {
        const opt = document.createElement("option");
        opt.value = i;
        opt.textContent = "Tier " + i;
        filter.appendChild(opt);
    }

    filter.onchange = () => {
        tierFilter = filter.value ? parseInt(filter.value) : null;
        update();
    };

    controls.appendChild(filter);

    container.appendChild(controls);

    const list = document.createElement("div");
    list.id = "levels";
    container.appendChild(list);
}

function render(entries) {
    const container = document.getElementById("levels");
    container.innerHTML = "";

    entries.forEach(level => {
        const thumb = `https://levelthumbs.prevter.me/thumbnail/${level["Level ID"]}`;

        const card = document.createElement("div");
        card.className = "level-card";

        card.innerHTML = `
        <img src="${thumb}" class="thumb">

        <div class="main">
            <h3>${level["Level"]}</h3>
            <p>Score: ${level["Score"]}/100</p>
            <p>Tier: ${level["Rating (GDDL)"]}</p>
        </div>

        <div class="details">
            <p><b>Enjoyment:</b> ${level["Experience/Enjoyment (GDDL)"]}/100</p>
            <p><b>Decoration:</b> ${level["Decoration Score"]}/100</p>
            <p><b>Gameplay:</b> ${level["Gameplay Score"]}/100</p>
            <p><b>Music:</b> ${level["Music Score"]}/100</p>
            <p><b>Attempts:</b> ${level["Attempts (from 0%)"]}</p>
            <p><b>Worst Fail:</b> ${level["Worst Fail"]}</p>
            <p><b>Note:</b> ${level["Note"]}</p>
            <a href="${level["Proof (GDDL)"]}" target="_blank">Proof</a>
        </div>
        `;

        card.onclick = () => {
            card.classList.toggle("open");
        };

        container.appendChild(card);
    });
}

function update() {

    let filtered = [...entries];

    if (tierFilter !== null) {
        filtered = filtered.filter(
            e => parseInt(e["Rating (GDDL)"]) === tierFilter
        );
    }

    if (currentSort) {
        filtered.sort((a, b) => {

            const A = parseFloat(a[currentSort]) || 0;
            const B = parseFloat(b[currentSort]) || 0;

            return ascending ? A - B : B - A;
        });
    }

    render(filtered);
}

document.addEventListener("DOMContentLoaded", () => {

    createControls();

    loadSheet().then(rows => {
        entries = rows.map(rowToObject);
        update();
    });

});