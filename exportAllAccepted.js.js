const { execSync } = require("child_process");
const fs = require("fs");

function getAcceptedSlugs() {
  const raw = execSync("leetcode list", { encoding: "utf-8" });
  const lines = raw.split("\n");
  const accepted = [];

  for (const line of lines) {
    if (line.includes("√")) {
      const match = line.match(/\[\s*(\d+)\s*\]/);
      if (match) {
        const id = match[1];
        const titleRaw = line.split("]").slice(1).join("]").trim();
        const title = titleRaw.split("  ")[0].trim();
        const slug = title
          .toLowerCase()
          .replace(/[^a-z0-9 ]/g, "")
          .replace(/\s+/g, "-");
        accepted.push(slug);
      }
    }
  }
  return accepted;
}

const slugs = getAcceptedSlugs();
const lang = "cpp";
const folder = "./problems";

if (!fs.existsSync(folder)) {
  fs.mkdirSync(folder);
}

slugs.forEach((slug, index) => {
  const filename = `${folder}/${slug}.${lang}`;
  try {
    const output = execSync(`leetcode show ${slug} -g -l ${lang}`, {
      encoding: "utf-8",
    });
    fs.writeFileSync(filename, output);
    console.log(`✅ [${index + 1}/${slugs.length}] Saved: ${filename}`);
  } catch (err) {
    console.log(`❌ [${index + 1}/${slugs.length}] Failed: ${slug}`);
  }
});
